-- Adminer 4.7.6 MySQL dump

SET NAMES utf8;
SET time_zone = '+00:00';
SET foreign_key_checks = 0;
SET sql_mode = 'NO_AUTO_VALUE_ON_ZERO';

USE `bts_tutorial`;

SET NAMES utf8mb4;

DROP TABLE IF EXISTS `jeux`;
CREATE TABLE `jeux` (
  `id_jeu` int(11) NOT NULL,
  `titre` varchar(20) NOT NULL,
  `annee_sorti` date NOT NULL,
  `pegi` int(11) NOT NULL,
  `nbmodes` int(11) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;


DROP TABLE IF EXISTS `JeuxPref`;
CREATE TABLE `JeuxPref` (
  `id_jeu` int(11) NOT NULL,
  `id_joueur` int(11) NOT NULL,
  `Pseudo` varchar(20) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;


DROP TABLE IF EXISTS `Joueur`;
CREATE TABLE `Joueur` (
  `id_joueur` int(30) unsigned DEFAULT NULL,
  `nom` varchar(15) NOT NULL,
  `prenom` varchar(15) NOT NULL,
  `date_naissance` date NOT NULL,
  `ville` varchar(30) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

INSERT INTO `Joueur` (`id_joueur`, `nom`, `prenom`, `date_naissance`, `ville`) VALUES
(NULL,	'Granger',	'Hermione',	'2000-03-12',	'Londres');

DROP TABLE IF EXISTS `Mesures`;
CREATE TABLE `Mesures` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `DATE` time NOT NULL DEFAULT current_timestamp(),
  `degres` float DEFAULT NULL,
  `humidie` float DEFAULT NULL,
  `pression` float DEFAULT NULL,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

INSERT INTO `Mesures` (`id`, `DATE`, `degres`, `humidie`, `pression`) VALUES
(1,	'19:40:50',	NULL,	NULL,	NULL),
(2,	'19:40:54',	NULL,	NULL,	NULL),
(3,	'19:40:58',	NULL,	NULL,	NULL),
(4,	'19:41:02',	NULL,	NULL,	NULL),
(5,	'19:41:20',	NULL,	NULL,	NULL),
(6,	'19:41:24',	NULL,	NULL,	NULL),
(7,	'19:46:36',	NULL,	NULL,	NULL),
(8,	'19:50:13',	NULL,	NULL,	NULL),
(9,	'19:50:29',	NULL,	NULL,	NULL),
(10,	'19:50:33',	NULL,	NULL,	NULL),
(11,	'20:01:28',	17.03,	69.72,	1004.06),
(12,	'20:01:32',	17.01,	69.74,	1004.08),
(13,	'20:01:36',	17.01,	69.66,	1004.09),
(14,	'20:01:40',	17.01,	69.72,	1004.08),
(15,	'20:01:44',	17.03,	69.7,	1004.13),
(16,	'20:01:48',	17.01,	69.72,	1004.2),
(17,	'20:01:52',	17.03,	69.72,	1004.12),
(18,	'00:01:23',	17.33,	71.77,	1006.72),
(19,	'00:01:27',	17.37,	71.85,	1006.67),
(20,	'00:01:31',	17.38,	71.82,	1006.77),
(21,	'00:01:35',	17.35,	71.85,	1006.73),
(22,	'00:01:39',	17.37,	71.79,	1006.82),
(23,	'00:01:43',	17.37,	71.81,	1006.79),
(24,	'00:01:47',	17.4,	71.8,	1006.76),
(25,	'00:01:51',	17.38,	71.81,	1006.69),
(26,	'00:01:55',	17.37,	71.85,	1006.71),
(27,	'00:01:59',	17.38,	71.79,	1006.69),
(28,	'00:02:03',	17.38,	71.75,	1006.74),
(29,	'00:02:07',	17.42,	71.8,	1006.73),
(30,	'00:02:11',	17.4,	71.84,	1006.7),
(31,	'00:02:15',	17.37,	71.85,	1006.78),
(32,	'00:06:00',	17.38,	71.8,	NULL),
(33,	'00:06:04',	17.42,	71.82,	1006.78),
(34,	'00:06:07',	17.4,	71.79,	NULL),
(35,	'00:07:14',	17.46,	71.7,	NULL),
(36,	'00:07:48',	17.46,	71.71,	1006.72),
(37,	'00:08:20',	NULL,	NULL,	NULL),
(38,	'00:11:38',	17.48,	71.67,	1006.7);

-- 2020-03-18 08:26:12
