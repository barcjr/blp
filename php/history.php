<html>
<head>
<title>BLP - PHP History</title>
<meta http-equiv="refresh" content="10" />
</head>
<body>
<div id="top">

<div id="title"><b>History</b></div>

<br />

<?php require('nav.php'); ?>

<br /> <br />

<?php
require_once('database.php');

$db_result = mysql_query("SELECT count(ContactID) FROM Contact") or die(mysql_error());
$row = mysql_fetch_array($db_result) or die(mysql_error());
$count = $row[0];
$db_result = mysql_query("SELECT count(ContactID) FROM Contact WHERE Time > SUBTIME(NOW(),'00:15:00') AND Time < NOW();") or die(mysql_error());
$row = mysql_fetch_array($db_result) or die(mysql_error());
$count15 = $row[0];
$day = date('d');
$hourInMin = date('H');
$min = date('i');
$rate = $count/(((24*($day-26)*60+($hourInMin-12)*60)+$min)/60);
$rate15 = $count15*4;


echo("<div id='count'>You have <b>$count</b> contacts! Thats an average of ".sprintf("%3.4d",$rate)." contacts per hour <br /> At that rate we'll get ".sprintf("%3.4d",$rate*24)." contacts This FieldDay!! <br />For the past 15 minutes the rate is <b>$rate15</b> contacts per hour.</div>");

?>

<br />

<table width="100%">
<tr><!--contact id, station id--><td>Time</td><td>Callsign</td><td>Class</td><td>Section</td>
<td>Frequency</td><td>Band/Mode</td></tr>

<?php
$query = "SELECT Contact.ContactID, Station.StationID, Contact.Time, Station.StationCall, Station.ContestClass, Section.FullName,
Contact.Frequency, BandMode.Title, MIN(NSContact.ContactID) FROM Contact
JOIN Station ON( Contact.StationID = Station.StationID )
JOIN Section ON( Station.SectionID = Section.SectionID )
JOIN BandMode ON( Contact.BandModeID = BandMode.BandModeID )
JOIN Station AS NSStation ON( NSStation.SectionID = Section.SectionID )
JOIN Contact AS NSContact ON( NSContact.StationID = NSStation.StationID )
GROUP BY Contact.ContactID
ORDER BY Contact.Time DESC
LIMIT 25";
$db_result = mysql_query($query) or die(mysql_error());

while($row = mysql_fetch_array($db_result)) {
  $contactid = $row[0];
  $stationid = $row[1];
  $time = $row[2];
  $call = $row[3];
  $class = $row[4];
  $section = $row[5];
  $frequency = $row[6]/1000000 . " MHz";
  $bandmode = $row[7];
if($row[0]==$row[8]){
$new="<b>(New)</b>";
} else {
$new="";
}
  echo "<tr><td>$time</td><td>$call</td><td>$class</td><td>$new $section</td><td>$frequency</td><td>$bandmode</td></tr>";
 }
?>
</table>
</div>
</body>
</html>
