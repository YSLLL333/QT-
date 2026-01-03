/*
 Navicat Premium Data Transfer

 Source Server         : book
 Source Server Type    : SQLite
 Source Server Version : 3035005 (3.35.5)
 Source Schema         : main

 Target Server Type    : SQLite
 Target Server Version : 3035005 (3.35.5)
 File Encoding         : 65001

 Date: 03/01/2026 19:57:21
*/

PRAGMA foreign_keys = false;

-- ----------------------------
-- Table structure for book
-- ----------------------------
DROP TABLE IF EXISTS "book";
CREATE TABLE "book" (
  "bookid" INTEGER NOT NULL PRIMARY KEY AUTOINCREMENT,
  "name" TEXT,
  "press" TEXT,
  "type1" TEXT,
  "type2" TEXT,
  "type3" TEXT,
  "cnt" integer,
  "pic" TEXT
);

-- ----------------------------
-- Records of book
-- ----------------------------

-- ----------------------------
-- Table structure for record
-- ----------------------------
DROP TABLE IF EXISTS "record";
CREATE TABLE "record" (
  " id" INTEGER NOT NULL PRIMARY KEY AUTOINCREMENT,
  "bookid" INTEGER,
  "userid" INTEGER,
  "start" TEXT,
  "end" TEXT,
  FOREIGN KEY ("bookid") REFERENCES "book" ("bookid") ON DELETE NO ACTION ON UPDATE NO ACTION,
  FOREIGN KEY ("userid") REFERENCES "user" ("userid") ON DELETE NO ACTION ON UPDATE NO ACTION
);

-- ----------------------------
-- Records of record
-- ----------------------------

-- ----------------------------
-- Table structure for sqlite_sequence
-- ----------------------------
DROP TABLE IF EXISTS "sqlite_sequence";
CREATE TABLE "sqlite_sequence" (
  "name",
  "seq"
);

-- ----------------------------
-- Records of sqlite_sequence
-- ----------------------------
INSERT INTO "sqlite_sequence" VALUES ('user', 0);
INSERT INTO "sqlite_sequence" VALUES ('record', 0);

-- ----------------------------
-- Table structure for user
-- ----------------------------
DROP TABLE IF EXISTS "user";
CREATE TABLE "user" (
  "userid" INTEGER NOT NULL PRIMARY KEY AUTOINCREMENT,
  "username" TEXT,
  "password" TEXT,
  "nickname" TEXT,
  "auth" TEXT,
  "department" TEXT,
  "grade" TEXT
);

-- ----------------------------
-- Records of user
-- ----------------------------

-- ----------------------------
-- Auto increment value for record
-- ----------------------------

-- ----------------------------
-- Auto increment value for user
-- ----------------------------

PRAGMA foreign_keys = true;
