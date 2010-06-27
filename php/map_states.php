<?PHP 
require('database.php'); 
#$mysql_res = mysql_query('select Distinct SectionID from Contact as c join Station as s on (c.StationID = s.StationID)');
$mysql_res = mysql_query('select SectionID from Section where NOT SectionID in (select SectionID from Contact as c join Station as s on (c.StationID = s.StationID))');
?>
<HTML> 
 
<HEAD> 
   <title>Jayzee Bear - USA Map</title> 
<script type="text/javascript" src="mapper/cvi_map_lib.js"></script>
<script type="text/javascript" src="jquery-1.4.2.min.js"></script>
<SCRIPT LANGUAGE="JavaScript"> 
$(document).ready(function() {
   // do stuff when DOM is ready
cvi_map.defaultRadius = 0;	 //INT 0-100 (px radius)
cvi_map.defaultOpacity = 100; //INT 0-100 (% opacity)
cvi_map.defaultBordercolor = '#000000'; //STR '#000000'-'#ffffff'
cvi_map.defaultAreacolor = '#ffffff'; //STR '#000000'-'#ffffff'
cvi_map.defaultNoborder = false; //BOOLEAN
cvi_map.defaultNofade = false; //BOOLEAN
cvi_map.defaultShowcoords = false; //BOOLEAN
cvi_map.defaultDelayed	 = false;	 //BOOLEAN
cvi_map.defaultImgsrc	 = 'usa.gif'; //STR (path&file)
cvi_map.defaultMapid	 = 'usa'; //STR (id)

cvi_map.add($('#usa')[0], {});
<? while($resArr = mysql_fetch_array($mysql_res)){echo "extAreaOver('usa','$resArr[0]')\n";} ?>

});
</SCRIPT> 
 
</head> 
 
<BODY  TEXT='black' LINK='blue' VLINK='blue' ALINK='blue'> 
 
<CENTER> 
 
<font face="Comic Sans Ms, Arial"><font size=5> 
UNITED STATES
</font></font> 
 
<br> 

<p align="center"> 
 
 
<MAP NAME="Map_USA"> 
 
<AREA SHAPE="POLYGON" COORDS="581, 74, 584, 83, 588, 83, 590, 78, 589, 75, 586, 74, 582, 74, 581, 74"  id="56"> 
 
 
 
<AREA SHAPE="POLYGON" COORDS="559, 119, 562, 116, 571, 128, 567, 132, 559, 118, 559, 119"  id="10"> 
 
 
 
 
 
 
<AREA SHAPE="POLYGON" COORDS="543, 126, 559, 119, 557, 133, 570, 131, 573, 136, 572, 139, 570, 139, 571, 145, 569, 148, 567, 144, 567, 139, 561, 133, 559, 126, 558, 126, 558, 132, 560, 134, 560, 140, 553, 136, 552, 131, 543, 126"  id="28"> 
<AREA SHAPE="POLYGON" COORDS="297, 65, 298, 115, 240, 119, 228, 123, 215, 101, 214, 95, 204, 86, 200, 65, 237, 68, 272, 68"  id="34"> 
<AREA SHAPE="POLYGON" COORDS="199, 64, 205, 91, 213, 97, 213, 103, 225, 122, 236, 122, 238, 155, 211, 156, 185, 151, 185, 125, 194, 112, 191, 100, 192, 63"  id="18"> 
<AREA SHAPE="POLYGON" COORDS="322, 167, 326, 210, 317, 214, 261, 215, 260, 168, 272, 165"  id="8"> 
<AREA SHAPE="POLYGON" COORDS="238, 157, 238, 164, 258, 166, 260, 216, 207, 216, 207, 156"  id="71"> 
<AREA SHAPE="POLYGON" COORDS="348, 217, 351, 240, 362, 244, 382, 246, 394, 240, 409, 243, 415, 259, 422, 273, 419, 289, 410, 289, 413, 297, 402, 308, 398, 308, 397, 311, 390, 319, 388, 326, 391, 340, 389, 343, 370, 341, 363, 326, 346, 310, 336, 304, 327, 309, 315, 312, 303, 299, 289, 283, 319, 278, 318, 222"  id="45"> 
<AREA SHAPE="POLYGON" COORDS="317, 215, 320, 275, 289, 281, 262, 286, 259, 218"  id="42"> 
<AREA SHAPE="POLYGON" COORDS="258, 218, 258, 283, 238, 286, 200, 270, 203, 260, 206, 251, 202, 235, 202, 228, 207, 228, 208, 214"  id="6"> 
<AREA SHAPE="POLYGON" COORDS="131, 102, 123, 119, 120, 134, 120, 140, 181, 151, 184, 126, 193, 111, 192, 104, 168, 104, 149, 104, 135, 98, 132, 98, 130, 107"  id="51"> 
<AREA SHAPE="POLYGON" COORDS="148, 60, 190, 64, 190, 88, 192, 100, 182, 102, 151, 105, 143, 100, 133, 94, 131, 66, 142, 66"  id="84"> 
<AREA SHAPE="POLYGON" COORDS="159, 149, 158, 185, 201, 237, 202, 228, 207, 227, 208, 155"  id="46"> 
<AREA SHAPE="POLYGON" COORDS="121, 144, 157, 148, 156, 186, 207, 248, 201, 259, 201, 263, 200, 267, 175, 267, 166, 254, 148, 240, 130, 211, 123, 193, 117, 166"  id="64"> 
<AREA SHAPE="POLYGON" COORDS="92, 0, 119, 23, 86, 90, 48, 73, 3, 76, 17, 56, 17, 22, 28, 7"  id="2"> 
<AREA SHAPE="POLYGON" COORDS="4, 274, 72, 274, 71, 343, 7, 345"  id="53"> 
<AREA SHAPE="POLYGON" COORDS="572, 159, 546, 169, 517, 177, 507, 177, 516, 167, 525, 166, 532, 159, 534, 148, 545, 130, 554, 140, 561, 144, 567, 148, 571, 154"  id="72"> 
<AREA SHAPE="POLYGON" COORDS="542, 127, 546, 129, 542, 131, 539, 140, 535, 146, 534, 154, 529, 163, 515, 166, 508, 157, 511, 145, 521, 132, 533, 132"  id="83"> 
<AREA SHAPE="POLYGON" COORDS="573, 103, 576, 115, 573, 122, 570, 122, 566, 118, 566, 112, 563, 106, 561, 98, 570, 96"  id="43"> 
<AREA SHAPE="POLYGON" COORDS="547, 50, 540, 60, 537, 76, 520, 87, 521, 101, 552, 91, 562, 95, 571, 97, 575, 99, 585, 91, 574, 91, 569, 82, 567, 71, 553, 51"  id="13"> 
<AREA SHAPE="POLYGON" COORDS="582, 77, 570, 81, 572, 92, 582, 87"  id="9"> 
<AREA SHAPE="POLYGON" COORDS="585, 61, 590, 68, 598, 68, 598, 73, 592, 76, 589, 74, 583, 74, 572, 83, 568, 73"  id="12"> 
<AREA SHAPE="POLYGON" COORDS="571, 38, 586, 56, 586, 60, 576, 67, 571, 61"  id="35"> 
<AREA SHAPE="POLYGON" COORDS="298, 116, 241, 118, 238, 164, 303, 163"  id="82"> 
<AREA SHAPE="POLYGON" COORDS="569, 38, 571, 63, 572, 68, 567, 71, 551, 49"  id="75"> 
<AREA SHAPE="POLYGON" COORDS="555, 92, 521, 102, 513, 103, 522, 132, 530, 129, 531, 132, 537, 128, 561, 118, 564, 112, 562, 103, 559, 97"  id="80"> 
<AREA SHAPE="POLYGON" COORDS="513, 106, 522, 131, 514, 141, 507, 155, 487, 155, 478, 137, 478, 125, 489, 119, 503, 117"  id="48"> 
<AREA SHAPE="POLYGON" COORDS="476, 126, 485, 154, 476, 170, 461, 177, 461, 162, 454, 131, 456, 127"  id="21"> 
<AREA SHAPE="POLYGON" COORDS="459, 127, 461, 115, 454, 102, 454, 92, 457, 84, 457, 77, 465, 71, 480, 81, 479, 94, 483, 90, 489, 97, 492, 102, 490, 109, 489, 116, 477, 121"  id="30"> 
<AREA SHAPE="POLYGON" COORDS="417, 77, 424, 84, 430, 79, 441, 84, 442, 91, 448, 123, 426, 129, 415, 121, 415, 113, 401, 100, 399, 85, 406, 74"  id="77"> 
<AREA SHAPE="POLYGON" COORDS="448, 123, 454, 131, 460, 158, 460, 182, 452, 191, 438, 182, 437, 173, 426, 166, 424, 155, 425, 144, 430, 135, 427, 128"  id="20"> 
<AREA SHAPE="POLYGON" COORDS="514, 168, 507, 157, 487, 156, 477, 170, 463, 177, 452, 195, 509, 181"  id="23"> 
<AREA SHAPE="POLYGON" COORDS="448, 200, 446, 214, 463, 214, 512, 203, 508, 197, 528, 175, 519, 177"  id="70"> 
<AREA SHAPE="POLYGON" COORDS="574, 158, 546, 167, 524, 176, 513, 188, 505, 201, 509, 201, 532, 190, 545, 190, 564, 194, 571, 185, 576, 163"  id="35"> 
<AREA SHAPE="POLYGON" COORDS="561, 197, 553, 192, 543, 193, 533, 190, 513, 199, 545, 231, 550, 221, 562, 201"  id="58"> 
<AREA SHAPE="POLYGON" COORDS="545, 249, 560, 266, 577, 294, 577, 310, 571, 314, 560, 307, 543, 283, 532, 270, 523, 265, 518, 270, 508, 267, 495, 265, 487, 267, 487, 262, 486, 260"  id="38"> 
<AREA SHAPE="POLYGON" COORDS="513, 200, 546, 230, 544, 247, 532, 252, 512, 253, 506, 235, 491, 206"  id="16"> 
<AREA SHAPE="POLYGON" COORDS="490, 207, 504, 233, 508, 250, 486, 258, 486, 264, 477, 269, 466, 215"  id="4"> 
<AREA SHAPE="POLYGON" COORDS="466, 214, 469, 244, 476, 268, 465, 274, 461, 268, 444, 269, 444, 254, 440, 238, 446, 216"  id="33"> 
<AREA SHAPE="POLYGON" COORDS="412, 256, 420, 273, 420, 286, 435, 291, 442, 287, 458, 293, 470, 291, 462, 269, 443, 270, 443, 253, 442, 250"  id="24"> 
<AREA SHAPE="POLYGON" COORDS="443, 205, 400, 205, 408, 229, 408, 239, 414, 251, 442, 249, 440, 236, 448, 211"  id="5"> 
<AREA SHAPE="POLYGON" COORDS="420, 156, 388, 162, 393, 178, 396, 186, 396, 195, 399, 206, 442, 204, 444, 207, 448, 207, 448, 200, 454, 191, 449, 187, 439, 181, 438, 176, 428, 169, 423, 161"  id="32"> 
<AREA SHAPE="POLYGON" COORDS="371, 127, 413, 119, 420, 125, 429, 134, 424, 144, 423, 153, 387, 161, 377, 143"  id="17"> 
<AREA SHAPE="POLYGON" COORDS="369, 57, 381, 60, 393, 57, 396, 59, 413, 56, 400, 81, 400, 86, 398, 92, 403, 103, 414, 117, 371, 124, 363, 96, 355, 60"  id="31"> 
<AREA SHAPE="POLYGON" COORDS="318, 216, 318, 221, 347, 218, 351, 238, 366, 241, 377, 248, 395, 241, 407, 241, 407, 230, 398, 206, 354, 208"  id="49"> 
<AREA SHAPE="POLYGON" COORDS="324, 178, 329, 211, 396, 204, 396, 182, 387, 164, 360, 174"  id="22"> 
<AREA SHAPE="POLYGON" COORDS="304, 140, 304, 163, 321, 165, 321, 175, 358, 175, 385, 166, 372, 132" id="37"> 
<AREA SHAPE="POLYGON" COORDS="301, 106, 363, 97, 369, 115, 371, 134, 304, 139"  id="60"> 
<AREA SHAPE="POLYGON" COORDS="297, 67, 353, 60, 361, 99, 303, 102"  id="36"> 
<AREA SHAPE="POLYGON" COORDS="571, 37, 576, 29, 574, 14, 582, 3, 592, 15, 600, 22, 596, 34, 590, 44, 587, 57, 584, 60"  id="29"> 
<AREA SHAPE="POLYGON" COORDS="410, 75, 433, 60, 432, 68, 449, 62, 448, 67, 434, 78, 420, 80"  id="Upper Peninsula of Michigan"> 
 
</MAP> 
 
<img class="mapper" id='usa' src="usa.gif" border="0" width="610" height="350" useMap="#Map_USA"> 
 
 
<SCRIPT Language="JavaScript"> 
</SCRIPT> 
 
</body> 
</html>
