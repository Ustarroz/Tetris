Lancement d'une moulinette de test Tetris
Attente d'un slot : ...................................................
Slot trouve.
Tests : ...........
Tests termines
Output :

Make environment
Running tests
Test 1
Testing whith --help
Killed
Test FAILED
Your output : 
Usage: ./tetris [options]$
Options:$
--help			Display this help$
-l --level={num}	Start Tetris at level num$
-kl --key-left={K}	Move tetrimino on LEFT with key K$
-kr --key-right={K}	Move tetrimino on RIGHT with key K$
-kt --key-turn={K}	Turn tetrimino with key K$
-kd --key-drop={K}	Set default DROP on key K$
-kq --key-quit={K}	Quit program when press key K$
-kp --key-pause={K}	Pause and restart game when press key K$
--map-size={row,col}	Set gamesize at row, col$
-w --without-next	Hide next tetrimino$
-d --debug		Debug mode$
Test 2
Testing whith --help and change binary name
Killed
TEST OK
Your output : 
Usage: ./mybin.18007 [options]$
Options:$
--help			Display this help$
-l --level={num}	Start Tetris at level num$
-kl --key-left={K}	Move tetrimino on LEFT with key K$
-kr --key-right={K}	Move tetrimino on RIGHT with key K$
-kt --key-turn={K}	Turn tetrimino with key K$
-kd --key-drop={K}	Set default DROP on key K$
-kq --key-quit={K}	Quit program when press key K$
-kp --key-pause={K}	Pause and restart game when press key K$
--map-size={row,col}	Set gamesize at row, col$
-w --without-next	Hide next tetrimino$
-d --debug		Debug mode$
Test 3
Testing whith bad parameter (1/5)
Killed
Test FAILED
Your output :
Test 4
Testing whith bad parameter (2/5)
Killed
TEST OK
Your output : 
Error: incorrect argument 1$
Test 5
Testing whith bad parameter (3/5)
Killed
TEST OK
Your output :
Error: incorrect argument 1$
Test 6
Testing whith bad parameter (4/5)
Killed
TEST OK
Your output : 
Error: incorrect argument 5$
Test 8
Testing key in debug mode - TERM=xterm
Killed
TEST OK
Your output :
*** DEBUG MODE ***$
Key Left : ^EOD$
Key Right : ^EOC$
Key Turn : ^EOA$
Key Drop : ^EOB$
Key Quit : q$
Key Pause : (space)$
Next : Yes$
Level : 1$
Size : 20*10$
Tetriminos : barre : Size 1*4 : Color 2 :$
*$
*$
*$
*$
Tetriminos : 5 : Size 1*1 : Color 4 :$
*$
Tetriminos : carre : Size 2*2 : Color 1 :$
**$
**$
Tetriminos : 7 : Size 5*4 : Color 3 :$
 * *$
* * *$
 * *$
  *$
Tetriminos : 4 : Error$
Tetriminos : L-Inverse : Size 2*3 : Color 5 :$
 *$
 *$
**$
Tetriminos : 6 : Size 2*3 : Color 6 :$
*$
**$
 *$
Press a key to start Tetris$
Test 9
Testing key in debug mode - TERM=vt100
Killed
TEST OK
Your output : 
*** DEBUG MODE ***$
Key Left : ^EOD$
Key Right : ^EOC$
Key Turn : ^EOA$
Key Drop : ^EOB$
Key Quit : q$
Key Pause : (space)$
Next : Yes$
Level : 1$
Size : 20*10$
Tetriminos : barre : Size 1*4 : Color 2 :$
*$
*$
*$
*$
Tetriminos : 5 : Size 1*1 : Color 4 :$
*$
Tetriminos : carre : Size 2*2 : Color 1 :$
**$
**$
Tetriminos : 7 : Size 5*4 : Color 3 :$
 * *$
* * *$
 * *$
  *$
Tetriminos : 4 : Error$
Tetriminos : L-Inverse : Size 2*3 : Color 5 :$
 *$
 *$
**$
Tetriminos : 6 : Size 2*3 : Color 6 :$
*$
**$
 *$
Press a key to start Tetris$
Test 10
Testing key in debug mode - TERM=aixterm
Killed
TEST OK
Your output : 
*** DEBUG MODE ***$
Key Left : ^E[D$
Key Right : ^E[C$
Key Turn : ^E[A$
Key Drop : ^E[B$
Key Quit : q$
Key Pause : (space)$
Next : Yes$
Level : 1$
Size : 20*10$
Tetriminos : barre : Size 1*4 : Color 2 :$
*$
*$
*$
*$
Tetriminos : 5 : Size 1*1 : Color 4 :$
*$
Tetriminos : carre : Size 2*2 : Color 1 :$
**$
**$
Tetriminos : 7 : Size 5*4 : Color 3 :$
 * *$
* * *$
 * *$
  *$
Tetriminos : 4 : Error$
Tetriminos : L-Inverse : Size 2*3 : Color 5 :$
 *$
 *$
**$
Tetriminos : 6 : Size 2*3 : Color 6 :$
*$
**$
 *$
Press a key to start Tetris$
Test 11
Testing with TERM=toto
Killed
TEST OK
Your output : 
'toto': unknown terminal type.$
Test 12
Testing with TERM=
Killed
TEST OK
Your output : 
'': unknown terminal type.$
Test 13
Testing without env
Killed
TEST OK
Your output : 
Test 14
Testing normal tetriminos
Killed
Test FAILED
Your output : 
*** DEBUG MODE ***$
Key Left : ^EOD$
Key Right : ^EOC$
Key Turn : ^EOA$
Key Drop : ^EOB$
Key Quit : q$
Key Pause : (space)$
Next : Yes$
Level : 1$
Size : 20*10$
Tetriminos : barre : Size 1*4 : Color 2 :$
*$
*$
*$
*$
Tetriminos : 5 : Size 1*1 : Color 4 :$
*$
Tetriminos : carre : Size 2*2 : Color 1 :$
**$
**$
Tetriminos : 7 : Size 5*4 : Color 3 :$
 * *$
* * *$
 * *$
  *$
Tetriminos : 4 : Error$
Tetriminos : L-Inverse : Size 2*3 : Color 5 :$
 *$
 *$
**$
Tetriminos : 6 : Size 2*3 : Color 6 :$
*$
**$
 *$
Press a key to start Tetris$
Test 15
Testing without tetriminos directory
Killed
TEST OK
Your output : 
no tetriminos available hereTest 16
Testing without tetriminos file
Killed
TEST OK
Your output : 
*** DEBUG MODE ***$
Key Left : ^EOD$
Key Right : ^EOC$
Key Turn : ^EOA$
Key Drop : ^EOB$
Key Quit : q$
Key Pause : (space)$
Next : Yes$
Level : 1$
Size : 20*10$
Press a key to start Tetris$
Segmentation fault (core dumped)$
Test 17
Testing with only one simple tetrimino
Killed
TEST OK
Your output : 
*** DEBUG MODE ***$
Key Left : ^EOD$
Key Right : ^EOC$
Key Turn : ^EOA$
Key Drop : ^EOB$
Key Quit : q$
Key Pause : (space)$
Next : Yes$
Level : 1$
Size : 20*10$
Tetriminos : a : Size 1*1 : Color 1 :$
*$
Press a key to start Tetris$
Test 18
Testing with only one simple tetrimino without 
 at end of file
Killed
TEST OK
Your output : 
*** DEBUG MODE ***$
Key Left : ^EOD$
Key Right : ^EOC$
Key Turn : ^EOA$
Key Drop : ^EOB$
Key Quit : q$
Key Pause : (space)$
Next : Yes$
Level : 1$
Size : 20*10$
Tetriminos : b : Size 1*1 : Color 1 :$
*$
Press a key to start Tetris$
Test 19
Testing with only one simple hidden tetrimino
Killed
TEST OK
Your output : 
*** DEBUG MODE ***$
Key Left : ^EOD$
Key Right : ^EOC$
Key Turn : ^EOA$
Key Drop : ^EOB$
Key Quit : q$
Key Pause : (space)$
Next : Yes$
Level : 1$
Size : 20*10$
Tetriminos : .c : Size 1*1 : Color 1 :$
*$
Press a key to start Tetris$
Terminated
Permalink : http://142.4.211.42:8000/tetris/log/puilla_e_9538a4b3df9a9661db49381e8b648ae7.log
Cleaning...

Result : 
KO
OK
KO
OK
OK
OK
OK
OK
OK
OK
OK
OK
KO
OK
OK
OK
OK
OK

Termine
Credits restant : 2
