-- MySQL dump 10.13  Distrib 8.0.34, for Win64 (x86_64)
--
-- Host: localhost    Database: games
-- ------------------------------------------------------
-- Server version	8.1.0
create database games;

use games;
/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!50503 SET NAMES utf8 */;
/*!40103 SET @OLD_TIME_ZONE=@@TIME_ZONE */;
/*!40103 SET TIME_ZONE='+00:00' */;
/*!40014 SET @OLD_UNIQUE_CHECKS=@@UNIQUE_CHECKS, UNIQUE_CHECKS=0 */;
/*!40014 SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0 */;
/*!40101 SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='NO_AUTO_VALUE_ON_ZERO' */;
/*!40111 SET @OLD_SQL_NOTES=@@SQL_NOTES, SQL_NOTES=0 */;

--
-- Table structure for table `desenvolvedora`
--

DROP TABLE IF EXISTS `desenvolvedora`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `desenvolvedora` (
  `id_desenvolvedora` int NOT NULL AUTO_INCREMENT,
  `nome` varchar(100) DEFAULT NULL,
  PRIMARY KEY (`id_desenvolvedora`)
) ENGINE=InnoDB AUTO_INCREMENT=6 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `desenvolvedora`
--

LOCK TABLES `desenvolvedora` WRITE;
/*!40000 ALTER TABLE `desenvolvedora` DISABLE KEYS */;
INSERT INTO `desenvolvedora` VALUES (1,'CD Projekt Red'),(2,'Nintendo'),(3,'Rockstar Games'),(4,'Ubisoft'),(5,'Valve Corporation');
/*!40000 ALTER TABLE `desenvolvedora` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `jogo`
--

DROP TABLE IF EXISTS `jogo`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `jogo` (
  `id_jogo` int NOT NULL AUTO_INCREMENT,
  `titulo` varchar(255) DEFAULT NULL,
  `genero` varchar(50) DEFAULT NULL,
  `preco` decimal(10,2) DEFAULT NULL,
  `fk_desenvolvedora` int DEFAULT NULL,
  PRIMARY KEY (`id_jogo`),
  KEY `fk_desenvolvedora` (`fk_desenvolvedora`),
  CONSTRAINT `jogo_ibfk_1` FOREIGN KEY (`fk_desenvolvedora`) REFERENCES `desenvolvedora` (`id_desenvolvedora`)
) ENGINE=InnoDB AUTO_INCREMENT=9 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `jogo`
--

LOCK TABLES `jogo` WRITE;
/*!40000 ALTER TABLE `jogo` DISABLE KEYS */;
INSERT INTO `jogo` VALUES (1,'Cyberpunk 2077','RPG',199.99,1),(2,'The Witcher 3','RPG',89.90,1),(3,'Zelda: BotW','Aventura',250.00,2),(4,'GTA V','Ação',79.99,3),(5,'AC Valhalla','RPG de Ação',179.90,4),(6,'Half-Life 2','FPS',39.99,5),(7,'RDR 2','Ação',129.99,3),(8,'Mario Odyssey','Plataforma',220.00,2);
/*!40000 ALTER TABLE `jogo` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `jogo_plataforma`
--

DROP TABLE IF EXISTS `jogo_plataforma`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `jogo_plataforma` (
  `id_jogo_plataforma` int NOT NULL AUTO_INCREMENT,
  `fk_jogo` int DEFAULT NULL,
  `fk_plataforma` int DEFAULT NULL,
  PRIMARY KEY (`id_jogo_plataforma`),
  KEY `fk_jogo` (`fk_jogo`),
  KEY `fk_plataforma` (`fk_plataforma`),
  CONSTRAINT `jogo_plataforma_ibfk_1` FOREIGN KEY (`fk_jogo`) REFERENCES `jogo` (`id_jogo`),
  CONSTRAINT `jogo_plataforma_ibfk_2` FOREIGN KEY (`fk_plataforma`) REFERENCES `plataforma` (`id_plataforma`)
) ENGINE=InnoDB AUTO_INCREMENT=11 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `jogo_plataforma`
--

LOCK TABLES `jogo_plataforma` WRITE;
/*!40000 ALTER TABLE `jogo_plataforma` DISABLE KEYS */;
INSERT INTO `jogo_plataforma` VALUES (1,1,1),(2,1,2),(3,2,1),(4,2,5),(5,3,4),(6,4,1),(7,4,5),(8,5,3),(9,7,1),(10,8,4);
/*!40000 ALTER TABLE `jogo_plataforma` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `plataforma`
--

DROP TABLE IF EXISTS `plataforma`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `plataforma` (
  `id_plataforma` int NOT NULL AUTO_INCREMENT,
  `nome_plataforma` varchar(100) DEFAULT NULL,
  PRIMARY KEY (`id_plataforma`)
) ENGINE=InnoDB AUTO_INCREMENT=6 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `plataforma`
--

LOCK TABLES `plataforma` WRITE;
/*!40000 ALTER TABLE `plataforma` DISABLE KEYS */;
INSERT INTO `plataforma` VALUES (1,'PC'),(2,'PlayStation 5'),(3,'Xbox Series X'),(4,'Nintendo Switch'),(5,'PlayStation 4');
/*!40000 ALTER TABLE `plataforma` ENABLE KEYS */;
UNLOCK TABLES;
/*!40103 SET TIME_ZONE=@OLD_TIME_ZONE */;

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;

-- Dump completed on 2025-06-27 14:29:58

-- Questões:

-- 1
select nome from desenvolvedora;

-- 2
select titulo, preco 
from jogo
where preco > 150;

-- 3
select nome_plataforma from plataforma;

-- 4
select titulo, nome
from jogo, desenvolvedora
where fk_desenvolvedora=id_desenvolvedora;

/*
select titulo, nome
from jogo, desenvolvedora
on fk_desenvolvedora=id_desenvolvedora 
*/

-- 5
select titulo, genero
from jogo
where genero="RPG";

-- 6
select titulo
from jogo
where titulo like "%Life%";

-- 7
select titulo
from jogo
where genero="Ação" or genero="FPS";
-- OU in("Ação", "FPS");

-- 8
select count(titulo), nome
from jogo join desenvolvedora 
on fk_desenvolvedora=id_desenvolvedora
group by nome; -- group by só funciona se tiver uma função agregada(count)

-- 9 
select avg(preco)
from jogo;

-- 10
/* Uma forma
select min(preco), min(titulo)
from jogo;

select max(preco), max(titulo)
from jogo;
*/

/* Outra forma
select titulo, preco
from jogo
where preco = (select max(preco) from jogo) or preco = (select min(preco) from jogo);
*/

select titulo, preco
from jogo
where preco = (select max(preco) from jogo)
union
select titulo, preco
from jogo
where preco = (select min(preco) from jogo);

-- 11
select nome, count(titulo) qtd
from jogo join desenvolvedora
on fk_desenvolvedora = id_desenvolvedora
group by nome having qtd > 1;

-- 12
select titulo, nome_plataforma
from jogo join jogo_plataforma
on fk_jogo = id_Jogo
join plataforma
on fk_plataforma = id_plataforma
order by titulo;

-- 13
select nome, nome_plataforma
from desenvolvedora
join jogo on fk_desenvolvedora = id_desenvolvedora
join jogo_plataforma on id_jogo = fk_jogo
join plataforma on id_plataforma = fk_plataforma
where nome_plataforma = "PlayStation 4";