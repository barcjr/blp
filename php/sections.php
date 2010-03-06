<html>
<head>
<title>BLP - PHP - Sections</title><meta http-equiv="refresh" content="10" />

</head>
<body>
<div id="title"><b>Sections Contacted</b></div>
<div>
<br />

<?php require('nav.php'); ?>

<br /> <br />

<?php
require_once('database.php');

$query = "SELECT Section.FullName, UNIX_TIMESTAMP(MIN(Contact.Time)) FROM Section
JOIN Station ON( Station.SectionID = Section.SectionID )
JOIN Contact ON( Contact.StationID = Station.StationID )
GROUP BY Section.SectionID;";

$db_result = mysql_query($query) or die(mysql_error());

while($row= mysql_fetch_array($db_result)) {
	if($row[1] > (time()-60))
		echo "<font color='#009900'>$row[0]</font><br />";
}
echo "<br />";

$query = "SELECT DISTINCT Section.FullName FROM Contact
JOIN Station ON (Contact.StationID = Station.StationID)
JOIN Section ON (Station.SectionID = Section.SectionID)
ORDER BY Section.FullName";

$db_result = mysql_query($query) or die(mysql_error());
$count = mysql_num_rows($db_result);
echo "<div id='count'>You have contacted - <b>$count</b></div>";
?>
<ul>
<?php
while($row = mysql_fetch_array($db_result)) {

  echo "<li>" . $row[0] . "</li>\n";

 }
?>
</ul>
</body>
</html>