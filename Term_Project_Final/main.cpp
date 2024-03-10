#include "lib.h"
#include "Board.h"
#include "Game2048.h"
/**
 * @brief 
 * # 初始化随机数发生器和游戏对象，进入游戏循环，并在游戏结束后输出时间和分数。
 * ## 游戏循环：
 * - 随机插入数字
 * - 打印棋盘
 * - 询问用户指令：
 * - 指令为方向则移动，移动后检测仍能移动则回到循环开始；否则退出循环。
 */
int main()
{
    random.setSeed(time(NULL));
    Dir dir;
    Game2048 g;
    g.randomInsert();
    do
    {
        g.randomInsert();
        g.printBoard();
        dir = g.queryDirection();
    } while (g.move(dir));
    return 0;
}