<html>
<head>
<title>BLP - PHP - Add User</title>
</head>
<body>
<h1>Add User</h1>
<?php
if($_GET['action'] == 'adduser' && $_GET['name'] != '' ) {

  require_once('database.php');

  $name = $_GET['name'];
  $callsign = $_GET['call'];
  mysql_query("INSERT INTO Operator (Name, CallSign) VALUES ('$name', '$callsign')") or die(mysql_error());
  echo "<div id='message'>Successfully added a new user with Name $name and a CallSign of $callsign <br /> You need to relaunch the BLP progam for your user to show up.</div>";
 }
?>
<div id="form">
<form action="adduser.php" method="get">
   Name : <input type="text" name="name" /><br />
   Callsign : <input type="text" name="call" /><br />
   <input type="hidden" value="adduser" name="action" />
   <input type="submit" value="Submit" />
</form>
</div>
</body>
</html>
