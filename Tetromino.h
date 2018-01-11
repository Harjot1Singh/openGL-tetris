#pragma once

#include "IDisplay.h"
#include "Grid.h"

/* Base class for Tetrominos */
class Tetromino : public Grid, public IDisplay {};

/* Class per Tetromino */
class I : public Tetromino {	I(); };
class O : public Tetromino {	O(); };
class T : public Tetromino {	T(); };
class L : public Tetromino {	L(); };
class J : public Tetromino {	J(); };
class Z : public Tetromino {	Z(); };
class S : public Tetromino {	S(); };
