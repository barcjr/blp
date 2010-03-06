-- MySQL dump 10.13  Distrib 5.1.37, for debian-linux-gnu (x86_64)
--
-- Host: 192.168.2.203    Database: FieldDay
-- ------------------------------------------------------
-- Server version	5.0.18

/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8 */;
/*!40103 SET @OLD_TIME_ZONE=@@TIME_ZONE */;
/*!40103 SET TIME_ZONE='+00:00' */;
/*!40014 SET @OLD_UNIQUE_CHECKS=@@UNIQUE_CHECKS, UNIQUE_CHECKS=0 */;
/*!40014 SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0 */;
/*!40101 SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='NO_AUTO_VALUE_ON_ZERO' */;
/*!40111 SET @OLD_SQL_NOTES=@@SQL_NOTES, SQL_NOTES=0 */;

--
-- Not dumping tablespaces as no INFORMATION_SCHEMA.FILES table on this server
--

--
-- Current Database: `FieldDay`
--

CREATE DATABASE /*!32312 IF NOT EXISTS*/ `FieldDay` /*!40100 DEFAULT CHARACTER SET latin1 */;

USE `FieldDay`;

--
-- Table structure for table `BandMode`
--

DROP TABLE IF EXISTS `BandMode`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `BandMode` (
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
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `BandMode`
--

LOCK TABLES `BandMode` WRITE;
/*!40000 ALTER TABLE `BandMode` DISABLE KEYS */;
INSERT INTO `BandMode` VALUES (18,'15m','CW',21000000,21200000,'15m CW',NULL),(35,'6m','Voice',50100000,54000000,' 6m Voice',NULL),(34,'6m','CW',50000000,54000000,' 6m CW',NULL),(14,'10m','Data',28000000,29700000,'10m Data',NULL),(13,'10m','CW',28000000,28300000,'10m CW',NULL),(12,'10m','Voice',28300000,29700000,'10m Voice',NULL),(19,'15m','Voice',21200000,21450000,'15m Voice',NULL),(20,'15m','Data',21000000,21450000,'15m Data',NULL),(24,'20m','CW',14000000,14150000,'20m CW',NULL),(25,'20m','Voice',14150000,14350000,'20m Voice',NULL),(26,'20m','Data',14000000,14350000,'20m Data',NULL),(28,'40m','CW',7000000,7125000,'40m CW',NULL),(29,'40m','Voice',7125000,7300000,'40m Voice',NULL),(30,'40m','Data',7000000,7300000,'40m Data',NULL),(31,'80m','CW',3500000,3600000,'80m CW',NULL),(33,'80m','Data',3500000,4000000,'80m Data',NULL),(36,'2m','Voice',144100000,148000000,' 2m Voice',NULL),(37,'80m','Voice',3600000,4000000,'80m Voice',NULL);
/*!40000 ALTER TABLE `BandMode` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `Contact`
--

DROP TABLE IF EXISTS `Contact`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `Contact` (
  `ContactID` int(11) unsigned NOT NULL auto_increment,
  `StationID` int(11) NOT NULL default '0',
  `RadioOp` int(11) NOT NULL default '0',
  `Logger` int(11) NOT NULL default '0',
  `Time` timestamp NOT NULL default CURRENT_TIMESTAMP,
  `BandModeID` int(11) NOT NULL default '0',
  `Frequency` double NOT NULL default '0',
  PRIMARY KEY  (`ContactID`)
) ENGINE=MyISAM DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `Contact`
--

LOCK TABLES `Contact` WRITE;
/*!40000 ALTER TABLE `Contact` DISABLE KEYS */;
/*!40000 ALTER TABLE `Contact` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `Operator`
--

DROP TABLE IF EXISTS `Operator`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `Operator` (
  `OperatorID` int(10) unsigned NOT NULL auto_increment,
  `Name` varchar(30) NOT NULL default '',
  `CallSign` varchar(10) NOT NULL default '',
  PRIMARY KEY  (`OperatorID`),
  UNIQUE KEY `Name` (`Name`,`CallSign`)
) ENGINE=MyISAM DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `Operator`
--

LOCK TABLES `Operator` WRITE;
/*!40000 ALTER TABLE `Operator` DISABLE KEYS */;
INSERT INTO `Operator` VALUES (1,'Bruce Arthur','KQ6TQ'),(2,'Ben Arthur','KC0ISG'),(8,'Brooke Garbarini',''),(4,'David Stearns','KC0DDR'),(5,'Hargobind Khalsa','AB0YL'),(6,'Karthik Kumar Rao','KC0WAZ'),(9,'Logan Garbarini','KC0WBA'),(10,'Kevin Johnk',''),(11,'Ben Johnk',''),(12,'Karun Kumar Rao','KC0WXC'),(13,'Matthew Kurek','KC0UGA'),(14,'Amanda Lee',''),(15,'Parker Meer',''),(16,'Roman Miller',''),(17,'Lucien Pullen','KC0TNP'),(18,'Megan Pullen',''),(19,'Gregory Pzredpelski','KC0RWR'),(21,'Danny Wisotzkey','KC0ULN'),(22,'Zhenghua yang','KC0QWA'),(23,'Julie Thomas',''),(24,'Josh Norman',''),(25,'Trenton Wright',''),(26,'Steve Stearns','AB0KB'),(27,'Don Lewis','KE0EE'),(28,'Charlie Raudonis','KH6GN'),(29,'Phil Miller','KC0UVQ'),(30,'Bob Johnk','WB0VGD'),(31,'Rick Wright',''),(32,'Melissa Wright',''),(33,'Su yang','KC0ULM'),(34,'Grant Kurek','W0GSK'),(35,'Jim Pullen','KC0TUZ'),(36,'Stephen Meer','K0SCC'),(37,'Gerry Leary','WB6IVF'),(38,'Dan Wisotzkey','N0NLS'),(39,'Dan Norman','N0HF'),(40,'Tom Pzredpelski','KC0FFW'),(41,'Ralph Bellamy','W0ZAY'),(42,'Terry Moore','KI0RE'),(43,'Greg Schlender','ND0V'),(44,'Mark Hasseman','KE0P'),(45,'Ben Hasseman','KD0ELP'),(46,'Marcus Kurek',''),(47,'Tyler Rector',''),(48,'Trevor Lawrence','KC0OJH'),(49,'Randall Oveson','KC0YPD'),(50,'samantha pimble',''),(51,'Jax Pimble',''),(52,'Daniel Steenburgh',''),(53,' Samantha Pimble',''),(77,'Alice Oveson',''),(55,'Avery Lemons',''),(56,'Mallory Oveson',''),(57,'Rich Weingarten','N0SH'),(58,'Rob Steenburgh','KA8JBY'),(59,'Mark Oveson','N0GG'),(60,'tommy','K6YE'),(61,'John',''),(62,'Jay Bender',''),(63,'Tori Buenemann',''),(64,'Logan Gillette','KD0CIT'),(65,'Caleb Kelsay',''),(66,'Merrick Kleppe',''),(67,'Kathlyn Leu',''),(68,'Logan Mitchell','KC0ATB'),(69,'Paul Stemmet','KD0DIW'),(70,'Ben Weingarten',''),(71,'Andy Yan',''),(72,'Kristin Wilson','KC0INX'),(76,'Ben Schupack','NW7DX'),(74,'Emily Milner','KD0BHA'),(73,'Brady Gordon','KD0BJS'),(78,'Marie Teto','KD0BQD'),(79,'Rich Gordon','KD0BJT'),(80,'Graham Gordon',''),(81,'Ed','WA4OHW'),(82,'Austin','KD0FAA'),(83,'Kurt','KD0HON'),(84,'Sam',''),(85,'Isaac','W0ISM'),(86,'Glendon Mavis',''),(87,'John Lee','KC0BID'),(88,'Zachary Lee',''),(89,'Brandin Frey',''),(90,'Olivier','KD0HOP'),(91,'Walt','KC0BPC'),(92,'Jesus Valdez Martinez',''),(93,'Joseph Valdez Martinez',''),(94,'Jonathan Troup','K0DE'),(95,'Christopher Guttormsson',''),(96,'Jacob Willson',''),(97,'Isaac Wilson',''),(98,'Kevin Kelly','');
/*!40000 ALTER TABLE `Operator` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `Section`
--

DROP TABLE IF EXISTS `Section`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `Section` (
  `SectionID` int(11) unsigned NOT NULL auto_increment,
  `Abbr` varchar(5) NOT NULL default '',
  `FullName` varchar(20) NOT NULL default '',
  PRIMARY KEY  (`SectionID`),
  UNIQUE KEY `Abbr_2` (`Abbr`),
  KEY `Abbr` (`Abbr`)
) ENGINE=MyISAM DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `Section`
--

LOCK TABLES `Section` WRITE;
/*!40000 ALTER TABLE `Section` DISABLE KEYS */;
INSERT INTO `Section` VALUES (80,'WPA','Western Pennsylvania'),(2,'AB','Alberta'),(3,'AK','Alaska'),(4,'AL','Alabama'),(5,'AR','Arkansas'),(6,'AZ','Arizona'),(7,'BC','British Columbia'),(8,'CO','Colorado'),(9,'CT','Connecticut'),(10,'DE','Delaware'),(11,'EB','East Bay'),(12,'EMA','Eastern Massachusett'),(13,'ENY','Eastern New York'),(14,'EPA','Eastern Pennsylvania'),(15,'EWA','Eastern Washington'),(16,'GA','Georgia'),(17,'IA','Iowa'),(18,'ID','Idaho'),(20,'IL','Illinois'),(21,'IN','Indianna'),(22,'KS','Kansas'),(23,'KY','Kentucky'),(24,'LA','Louisiana'),(25,'LAX','Los Angeles'),(26,'MAR','Maritime'),(27,'MB','Manitoba'),(28,'MDC','Maryland-DC'),(29,'ME','Maine'),(30,'MI','Michigan'),(31,'MN','Minnesota'),(32,'MO','Missouri'),(33,'MS','Mississippi'),(34,'MT','Montana'),(35,'NC','North Carolina'),(36,'ND','North Dakota'),(37,'NE','Nebraska'),(38,'NFL','Northern Florida'),(39,'NH','New Hampshire'),(40,'NL','Newfoundland - Labra'),(41,'NLI','New York-Long Island'),(42,'NM','New Mexico'),(43,'NNJ','Northern New Jersey'),(44,'NNY','Northern New York'),(45,'NTX','North Texas'),(46,'NV','Nevada'),(47,'NT','North West Territory'),(48,'OH','Ohio'),(49,'OK','Oklahoma'),(50,'ON','Ontario'),(51,'OR','Oregon'),(52,'ORG','Orange'),(53,'PAC','Pacific'),(54,'PR','Puerto Rico'),(55,'QC','Quebec'),(56,'RI','Rhode Island'),(57,'SB','Santa Barbara'),(58,'SC','South Carolina'),(59,'SCV','Santa Clara Valley'),(60,'SD','South Dakota'),(61,'SDG','San Diego'),(62,'SF','San Francisco'),(63,'SFL','Southern Flordia'),(64,'SJV','San Joaquin Valley'),(65,'SK','Saskatchewan'),(66,'SNJ','Southern New Jersey'),(67,'SNY','Southern New York'),(68,'STX','South Texas'),(69,'SV','Sacramento Vallley'),(70,'TN','Tennessee'),(71,'UT','Utah'),(72,'VA','Virginia'),(74,'VI','Virgin Islands'),(75,'VT','Vermont'),(76,'WCF','West Central Flordia'),(77,'WI','Wisconsin'),(78,'WMA','Western Massachusett'),(79,'WNY','Western New York'),(81,'WTX','West Texas'),(82,'WY','Wyoming'),(83,'WV','West Virginia'),(84,'WWA','Western Washington'),(85,'DX','DX');
/*!40000 ALTER TABLE `Section` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `Station`
--

DROP TABLE IF EXISTS `Station`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `Station` (
  `StationID` int(11) unsigned NOT NULL auto_increment,
  `StationCall` varchar(10) NOT NULL default '',
  `SectionID` int(11) NOT NULL default '0',
  `ContestClass` varchar(6) NOT NULL default '',
  `Notes` varchar(30) NOT NULL default '',
  PRIMARY KEY  (`StationID`),
  UNIQUE KEY `StationCall` (`StationCall`),
  FULLTEXT KEY `StationCall_2` (`StationCall`)
) ENGINE=MyISAM DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `Station`
--

LOCK TABLES `Station` WRITE;
/*!40000 ALTER TABLE `Station` DISABLE KEYS */;
/*!40000 ALTER TABLE `Station` ENABLE KEYS */;
UNLOCK TABLES;
/*!40103 SET TIME_ZONE=@OLD_TIME_ZONE */;

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;

-- Dump completed on 2010-03-06 15:08:23
