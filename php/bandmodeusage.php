<!DOCTYPE html>
<html>
  <head>
    <title>BLP - Band/Mode Usage</title>
    <meta http-equiv="refresh" content="10" />
  </head>
  <body>
    <div id="title"><b>Band/Mode Usage</b></div>
    <br>
    <?php require('nav.php'); ?>
    <br><br>

    <table>
      <tr>
        <th>Band/Mode</th>
        <th>In use by</th>
      </tr>
      <?php
      require_once('database.php');
      
      $db_result = mysql_query('SELECT Title, CurrentUser FROM BandMode WHERE CurrentUser IS NOT NULL') or die(mysql_error());
      while($row = mysql_fetch_array($db_result)) {
        $title = $row[0];
        $user = $row[1];

        echo "<tr><td>$title</td><td>$user</td></tr>";
      }
      ?>
    </table>
  </body>
</html>

