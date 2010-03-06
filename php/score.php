<html>
<head>
<title>BLP - PHP Score</title>
<meta http-equiv="refresh" content="10" />
</head>
<body>
<div id="top">

<div id="title"><b>Score</b></div>

<br />

<?php require('nav.php'); ?>

<br /> <br />

<?php
require_once('database.php');

$db_result = mysql_query("SELECT count(ContactID) FROM Contact") or die(mysql_error());
$row = mysql_fetch_array($db_result) or die(mysql_error());
$count = $row[0];
echo("You have <b>$count</b> contacts!<br />");
?>


<?php
$query = "SELECT Contact.ContactID, Station.StationID, Contact.Time, Station.StationCall, Station.ContestClass, Section.FullName,
Contact.Frequency, BandMode.Title FROM Contact
JOIN Station ON( Contact.StationID = Station.StationID )
JOIN Section ON( Station.SectionID = Section.SectionID )
JOIN BandMode ON( Contact.BandModeID = BandMode.BandModeID )
ORDER BY Contact.Time DESC
";
$db_result = mysql_query($query) or die(mysql_error());
 
$cwCount = 0;
$voiceCount= 0;
$dataCount = 0;
while($row = mysql_fetch_array($db_result)) {
  
  $contactid = $row[0];
  $stationid = $row[1];
  $time = $row[2];
  $call = $row[3];
  $class = $row[4];
  $section = $row[5];
  $frequency = $row[6]/1000000 . " MHz";
  $bandmode = $row[7];
  
  if(preg_match('/Voice/',$bandmode)){
    $voiceCount++;
  }elseif(preg_match('/CW/',$bandmode)){
    $cwCount++;
  }elseif(preg_match('/Data/',$bandmode)){
    $dataCount++;
  }
 }
echo "Number of CW Contacts: $cwCount<br />";
echo "Number of Voice Contacts: $voiceCount<br />";
echo "Number of Data Contact: $dataCount<br />";
$totalCount = $voiceCount + (2*$dataCount) + (2*$cwCount);
echo "<b>Total Score: $totalCount</b><br />";
?>
</div>
</body>
</html>
