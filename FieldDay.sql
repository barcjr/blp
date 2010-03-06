-- MySQL Administrator dump 1.4
--
-- ------------------------------------------------------
-- Server version	5.0.18


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8 */;

/*!40014 SET @OLD_UNIQUE_CHECKS=@@UNIQUE_CHECKS, UNIQUE_CHECKS=0 */;
/*!40014 SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0 */;
/*!40101 SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='NO_AUTO_VALUE_ON_ZERO' */;


--
-- Create schema FieldDay
--

CREATE DATABASE IF NOT EXISTS FieldDay;
USE FieldDay;

--
-- Definition of table `FieldDay`.`BandMode`
--

DROP TABLE IF EXISTS `FieldDay`.`BandMode`;
CREATE TABLE  `FieldDay`.`BandMode` (
  `BandModeID` int(11) unsigned NOT NULL auto_increment,
  `Band` varchar(10) NOT NULL default '',
  `Mode` varchar(10) NOT NULL default '',
  `LowerFreq` double NOT NULL default '0',
  `UpperFreq` double NOT NULL default '0',
  `Title` varchar(15) NOT NULL default '',
  `CurrentUser` varchar(64) default NULL,
  PRIMARY KEY  (`BandModeID`),
  UNIQUE KEY `Title` (`Title`)
) ENGINE=MyISAM DEFAULT CHARSET=latin1;

--
-- Dumping data for table `FieldDay`.`BandMode`
--

/*!40000 ALTER TABLE `BandMode` DISABLE KEYS */;
LOCK TABLES `BandMode` WRITE;
INSERT INTO `FieldDay`.`BandMode` VALUES  (18,'15m','cw',21000000,21200000,'15m CW',NULL),
 (35,'6m','Voice',50100000,54000000,' 6m Voice',NULL),
 (34,'6m','cw',50000000,54000000,' 6m CW',NULL),
 (14,'10m','Data',28000000,29700000,'10m Data',NULL),
 (13,'10m','cw',28000000,28300000,'10 CW',NULL),
 (12,'10m','voice',28300000,29700000,'10m Voice',NULL),
 (19,'15m','voice',21200000,21450000,'15m Voice',NULL),
 (20,'15m','Data',21000000,21450000,'15m Data',NULL),
 (24,'20m','cw',14000000,14150000,'20m CW',NULL),
 (25,'20m','Voice',14150000,14350000,'20m Voice',NULL),
 (26,'20m','Data',14000000,14350000,'20m Data',NULL),
 (28,'40m','cw',7000000,7150000,'40m CW',NULL),
 (29,'40m','Voice',7150000,7300000,'40m Voice',NULL),
 (30,'40m','Data',7000000,7300000,'40m Data',NULL),
 (31,'80m','cw',3500000,3750000,'80m CW',NULL),
 (32,'75m','Voice',3.75,4000000,'75m Voice',NULL),
 (33,'80m','Data',3500000,3750000,'80m Data',NULL),
 (36,'2m','Voice',144000000,148000000,' 2m Voice',NULL);
UNLOCK TABLES;
/*!40000 ALTER TABLE `BandMode` ENABLE KEYS */;


--
-- Definition of table `FieldDay`.`Contact`
--

DROP TABLE IF EXISTS `FieldDay`.`Contact`;
CREATE TABLE  `FieldDay`.`Contact` (
  `ContactID` int(11) unsigned NOT NULL auto_increment,
  `StationID` int(11) NOT NULL default '0',
  `RadioOp` int(11) NOT NULL default '0',
  `Logger` int(11) NOT NULL default '0',
  `Time` timestamp NOT NULL default CURRENT_TIMESTAMP,
  `BandModeID` int(11) NOT NULL default '0',
  `Frequency` double NOT NULL default '0',
  PRIMARY KEY  (`ContactID`)
) ENGINE=MyISAM DEFAULT CHARSET=latin1;

--
-- Dumping data for table `FieldDay`.`Contact`
--

/*!40000 ALTER TABLE `Contact` DISABLE KEYS */;
LOCK TABLES `Contact` WRITE;
INSERT INTO `FieldDay`.`Contact` VALUES  (31,31,5,22,'2006-06-24 13:40:44',26,14070400),
 (32,32,22,19,'2006-06-24 13:50:42',26,14070400),
 (106,105,25,39,'2006-06-24 19:33:45',25,14247400),
 (34,34,24,17,'2006-06-24 13:59:32',25,14282100),
 (35,35,22,19,'2006-06-24 14:01:11',26,14070400),
 (36,36,24,17,'2006-06-24 14:08:54',25,14213100),
 (37,37,22,19,'2006-06-24 14:11:35',26,14070400),
 (38,38,24,17,'2006-06-24 14:20:48',25,14260100),
 (39,39,23,17,'2006-06-24 14:22:58',25,14295000),
 (40,40,23,17,'2006-06-24 14:24:17',25,14315200),
 (41,41,39,13,'2006-06-24 14:27:41',25,14288900),
 (42,42,39,13,'2006-06-24 14:28:23',25,14288900),
 (43,43,39,13,'2006-06-24 14:30:36',25,14288900),
 (44,44,39,13,'2006-06-24 14:31:53',25,14288900),
 (45,45,39,13,'2006-06-24 14:32:24',25,14288900),
 (46,46,39,13,'2006-06-24 14:33:33',25,14288900),
 (47,47,39,13,'2006-06-24 14:34:12',25,14288900),
 (48,48,39,13,'2006-06-24 14:34:30',25,14288900),
 (49,49,39,13,'2006-06-24 14:34:56',25,14288900),
 (50,50,39,13,'2006-06-24 14:35:14',25,14288900),
 (51,51,39,13,'2006-06-24 14:35:51',25,14288900);
INSERT INTO `FieldDay`.`Contact` VALUES  (52,52,39,13,'2006-06-24 14:36:58',25,14288900),
 (53,53,39,13,'2006-06-24 14:38:08',25,14288900),
 (54,54,39,13,'2006-06-24 14:38:41',25,14288900),
 (55,55,39,13,'2006-06-24 14:42:49',25,14298900),
 (56,56,10,10,'2006-06-24 14:43:26',35,50200000),
 (57,57,39,13,'2006-06-24 14:44:07',25,14298900),
 (58,58,22,6,'2006-06-24 14:45:48',26,14072300),
 (59,59,6,13,'2006-06-24 14:45:48',25,14298900),
 (60,60,22,6,'2006-06-24 14:47:12',26,14072300);
UNLOCK TABLES;
/*!40000 ALTER TABLE `Contact` ENABLE KEYS */;


--
-- Definition of table `FieldDay`.`Operator`
--

DROP TABLE IF EXISTS `FieldDay`.`Operator`;
CREATE TABLE  `FieldDay`.`Operator` (
  `OperatorID` int(10) unsigned NOT NULL auto_increment,
  `Name` varchar(30) NOT NULL default '',
  `CallSign` varchar(10) NOT NULL default '',
  PRIMARY KEY  (`OperatorID`),
  UNIQUE KEY `Name` (`Name`,`CallSign`)
) ENGINE=MyISAM DEFAULT CHARSET=latin1;

--
-- Dumping data for table `FieldDay`.`Operator`
--

/*!40000 ALTER TABLE `Operator` DISABLE KEYS */;
LOCK TABLES `Operator` WRITE;
INSERT INTO `FieldDay`.`Operator` VALUES  (1,'Bruce Arthur','KQ6TQ'),
 (2,'Ben Arthur','KC0ISG'),
 (8,'Brooke Garbarini',''),
 (4,'David Stearns','KC0DDR'),
 (5,'Hargobind Khalsa','AB0YL'),
 (6,'Karthik Kumar Rao','KC0WAZ'),
 (9,'Logan Garbarini','KC0WBA'),
 (10,'Kevin Johnk',''),
 (11,'Ben Johnk',''),
 (12,'Karun Kumar Rao','KC0WXC'),
 (13,'Matthew Kurek','KC0UGA'),
 (14,'Amanda Lee',''),
 (15,'Parker Meer',''),
 (16,'Roman Miller',''),
 (17,'Lucien Pullen','KC0TNP'),
 (18,'Megan Pullen',''),
 (19,'Gregory Pzredpelski','KC0RWR'),
 (21,'Danny Wisotzkey','KC0ULN'),
 (22,'Zhenghua yang','KC0QWA'),
 (23,'Julie Thomas',''),
 (24,'Josh Norman',''),
 (25,'Trenton Wright',''),
 (26,'Steve Stearns','KB0AB'),
 (27,'Don Lewis','KE0EE'),
 (28,'Charlie Raudonis','KH6GN'),
 (29,'Phil Miller','KC0UVQ'),
 (30,'Bob Johnk','WB0VGD'),
 (31,'Rick Wright',''),
 (32,'Melissa Wright',''),
 (33,'Su yang','KC0ULM'),
 (34,'Grant Kurek','W0GSK'),
 (35,'Jim Pullen','KC0TUZ'),
 (36,'Stephen Meer','K0SCC'),
 (37,'Gerry Leary','WB6IVF'),
 (38,'Dan Wisotzkey','N0NLS');
INSERT INTO `FieldDay`.`Operator` VALUES  (39,'Dan Norman','N0HF'),
 (40,'Tom Pzredpelski','KC0FFW'),
 (41,'Ralph Bellamy','W0ZAY'),
 (42,'Terry Moore','KI0RE'),
 (43,'Greg Schlender','ND0V'),
 (44,'Mark Hasseman','KE0P'),
 (45,'Ben Hasseman',''),
 (46,'Marcus Kurek',''),
 (47,'Tyler Rector','');
UNLOCK TABLES;
/*!40000 ALTER TABLE `Operator` ENABLE KEYS */;


--
-- Definition of table `FieldDay`.`Section`
--

DROP TABLE IF EXISTS `FieldDay`.`Section`;
CREATE TABLE  `FieldDay`.`Section` (
  `SectionID` int(11) unsigned NOT NULL auto_increment,
  `Abbr` varchar(5) NOT NULL default '',
  `FullName` varchar(20) NOT NULL default '',
  PRIMARY KEY  (`SectionID`),
  UNIQUE KEY `Abbr_2` (`Abbr`),
  KEY `Abbr` (`Abbr`)
) ENGINE=MyISAM DEFAULT CHARSET=latin1;

--
-- Dumping data for table `FieldDay`.`Section`
--

/*!40000 ALTER TABLE `Section` DISABLE KEYS */;
LOCK TABLES `Section` WRITE;
INSERT INTO `FieldDay`.`Section` VALUES  (80,'WPA','Western Pennsylvania'),
 (2,'AB','Alberta'),
 (3,'AK','Alaska'),
 (4,'AL','Alabama'),
 (5,'AR','Arkansas'),
 (6,'AZ','Arizona'),
 (7,'BC','British Columbia'),
 (8,'CO','Colorado'),
 (9,'CT','Connecticut'),
 (10,'DE','Delaware'),
 (11,'EB','East Bay'),
 (12,'EMA','Eastern Massachusett'),
 (13,'ENY','Eastern New York'),
 (14,'EPA','Eastern Pennsylvania'),
 (15,'EWA','Eastern Washington'),
 (16,'GA','Georgia'),
 (17,'IA','Iowa'),
 (18,'ID','Idaho'),
 (20,'IL','Illinois'),
 (21,'IN','Indianna'),
 (22,'KS','Kansas'),
 (23,'KY','Kentucky'),
 (24,'LA','Louisiana'),
 (25,'LAX','Los Angeles'),
 (26,'MAR','Maritime'),
 (27,'MB','Manitoba'),
 (28,'MDC','Maryland-DC'),
 (29,'ME','Maine'),
 (30,'MI','Michigan'),
 (31,'MN','Minnesota'),
 (32,'MO','Missouri'),
 (33,'MS','Mississippi'),
 (34,'MT','Montana'),
 (35,'NC','North Carolina'),
 (36,'ND','North Dakota'),
 (37,'NE','Nebraska'),
 (38,'NFL','Northern Florida'),
 (39,'NH','New Hampshire'),
 (40,'NL','Newfoundland - Labra'),
 (41,'NLI','New York-Long Island');
INSERT INTO `FieldDay`.`Section` VALUES  (42,'NM','New Mexico'),
 (43,'NNJ','Northern New Jersey'),
 (44,'NNY','Northern New York'),
 (45,'NTX','North Texas'),
 (46,'NV','Nevada'),
 (47,'NT','North West Territory'),
 (48,'OH','Ohio'),
 (49,'OK','Oklahoma'),
 (50,'ON','Ontario'),
 (51,'OR','Oregon'),
 (52,'ORG','Orange'),
 (53,'PAC','Pacific'),
 (54,'PR','Puerto Rico'),
 (55,'QC','Quebec'),
 (56,'RI','Rhode Island'),
 (57,'SB','Santa Barbara'),
 (58,'SC','South Carolina'),
 (59,'SCV','Santa Clara Valley'),
 (60,'SD','South Dakota'),
 (61,'SDG','San Diego'),
 (62,'SF','San Francisco'),
 (63,'SFL','Southern Flordia'),
 (64,'SJV','San Joaquin Valley'),
 (65,'SK','Saskatchewan'),
 (66,'SNJ','Southern New Jersey'),
 (67,'SNY',''),
 (68,'STX','South Texas'),
 (69,'SV','Sacramento Vallley'),
 (70,'TN','Tennessee'),
 (71,'UT','Utah'),
 (72,'VA','Virginia'),
 (73,'VE8',''),
 (74,'VI','Virgin Islands'),
 (75,'VT','Vermont'),
 (76,'WCF','West Central Flordia'),
 (77,'WI','Wisconsin'),
 (78,'WMA','Western Massachusett'),
 (79,'WNY','Western New York');
INSERT INTO `FieldDay`.`Section` VALUES  (81,'WTX','West Texas'),
 (82,'WY','Wyoming'),
 (83,'WV','West Virginia'),
 (84,'WWA','Western Washington');
UNLOCK TABLES;
/*!40000 ALTER TABLE `Section` ENABLE KEYS */;


--
-- Definition of table `FieldDay`.`Station`
--

DROP TABLE IF EXISTS `FieldDay`.`Station`;
CREATE TABLE  `FieldDay`.`Station` (
  `StationID` int(11) unsigned NOT NULL auto_increment,
  `StationCall` varchar(10) NOT NULL default '',
  `SectionID` int(11) NOT NULL default '0',
  `ContestClass` varchar(6) NOT NULL default '',
  `Notes` varchar(30) NOT NULL default '',
  PRIMARY KEY  (`StationID`),
  UNIQUE KEY `StationCall` (`StationCall`),
  FULLTEXT KEY `StationCall_2` (`StationCall`)
) ENGINE=MyISAM DEFAULT CHARSET=latin1;

--
-- Dumping data for table `FieldDay`.`Station`
--

/*!40000 ALTER TABLE `Station` DISABLE KEYS */;
LOCK TABLES `Station` WRITE;
UNLOCK TABLES;
/*!40000 ALTER TABLE `Station` ENABLE KEYS */;




/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
