<?php
$db_host = "localhost";
$db_user = "root";
$db_pass = "";
$db_database = "FieldDay";
$db_connection = mysql_connect($db_host, $db_user, $db_pass) or die("Database error: " . mysql_error());
mysql_query("USE FieldDay");
?>
