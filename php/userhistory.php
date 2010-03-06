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
?>

<?php
$db_result = mysql_query("SELECT Name, CallSign, OperatorID FROM Operator ORDER BY Name");
?>
<form action="userhistory.php" method="get">
   <select name="user">
<?php
while( $row = mysql_fetch_array($db_result) ) {
  $name = $row[0];
  $call = $row[1];
  $id = $row[2];
  $selected = "";
  if( $_GET['user'] == $id ) $selected = " selected ";
  echo("<option $selected value=\"$id\">$name ($call)</option>");
}
?>
   </select>
   <input type="submit" value="Update" />
</form>
<?php

   if( array_key_exists('user', $_GET) ) {


     $id = $_GET['user'];

     $db_result = mysql_query("SELECT Name FROM Operator WHERE OperatorID=$id;");
     $row = mysql_fetch_array($db_result);

     $name = $row[0];

$db_result = mysql_query("SELECT count(ContactID) FROM Contact WHERE RadioOp=$id") or die(mysql_error());
$row = mysql_fetch_array($db_result) or die(mysql_error());
$count = $row[0];
echo("<div id='count'>$name has <b>$count</b> contacts as Operator!</div>");

$db_result = mysql_query("SELECT count(ContactID) FROM Contact WHERE Logger=$id") or die(mysql_error());
$row = mysql_fetch_array($db_result) or die(mysql_error());
$count = $row[0];
echo("<div id='count'>$name has <b>$count</b> contacts as Logger!</div>");

$db_result = mysql_query("SELECT count(ContactID) FROM Contact WHERE Logger=$id OR RadioOp=$id") or die(mysql_error());
$row = mysql_fetch_array($db_result) or die(mysql_error());
$count = $row[0];
echo("<div id='count'>$name has <b>$count</b> contacts total!</div>");
?>

<br />


<b>Contacts Made as Logger</b>
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
WHERE Contact.Logger = $id
GROUP BY Contact.ContactID
ORDER BY Contact.Time DESC";
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
  if($row[0]==$row[8]) {
    $new="<b>(New)</b>";
  } else {
    $new="";
  }
  echo "<tr><td>$time</td><td>$call</td><td>$class</td><td>$new $section</td><td>$frequency</td><td>$bandmode</td></tr>";
 }
?>
</table>


<b>Contacts Made as Operator</b>
<table width="100%">
<tr><!--contact id, station id--><td>Time</td><td>Callsign</td><td>Class</td><td>Section</td>
<td>Frequency</td><td>Band/Mode</td></tr>

<?php
$query = "SELECT Contact.ContactID, Station.StationID, Contact.Time, Station.StationCall, Station.ContestClass, Section.FullName,
Contact.Frequency, BandMode.Title FROM Contact
JOIN Station ON( Contact.StationID = Station.StationID )
JOIN Section ON( Station.SectionID = Section.SectionID )
JOIN BandMode ON( Contact.BandModeID = BandMode.BandModeID )
WHERE Contact.RadioOp = $id
ORDER BY Contact.Time DESC";
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
  echo "<tr><td>$time</td><td>$call</td><td>$class</td><td>$section</td><td>$frequency</td><td>$bandmode</td></tr>";
 }
?>
</table>

<?php } ?>

</div>



</body>
</html>
