#include<curses.h>
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include<time.h>


int main(void)
{
    int zx = 5;
    int zy = 9;
    srand(time(NULL));
    initscr();
    noecho();
    curs_set(0);
    
    int bx = rand() % (35 + 1 - 0) + 0;
    int by = rand() % (15 + 1 - 0) + 0;
    int lflag = 0;
    int ex = rand() % (35 + 1 - 0) + 0;
    int ey = rand() % (15 + 1 - 0) + 0;

    
   
    WINDOW * win = newwin(20, 40, 0, 0);

    keypad(win, 1);
    int tflag = 1;
    int hflag = 0;

    int ch;
    int u;
    int e;
    int j;
    int d;
    char cig[5] = {'.', '>', 'Z', ',', 'R'};
    int life = 20;
    char lifec[] = "life:";
    do
    {
      int dx = zx - bx;
      int dy = zy - by;
      wclear(win);
      box(win, 0, 0);
      if (ch == 'w') zy--;
      if (ch == 's') zy++;
      if (ch == 'a') zx--;
      if (ch == 'd') zx++;
      mvwaddch(win, zy, zx, cig[2]);
      mvwaddch(win, ey, ex, cig[1]);
      mvwaddch(win, by, bx, cig[4]);
      mvwaddstr(win, 19, 0, lifec);
      mvprintw(10, 50, "LEGEND:");
      mvprintw(11, 50, "@: JOHN ZEITGEIST");
      mvprintw(12, 50, "m: MUGGER");
      mvwprintw(win, 19, 5, "%d", life);
      wbkgd(win, cig[0]);
      if (tflag == 1) {
        mvwaddstr(win, 0, 0, "WELCOME TO ZEITGEIST");
      }
      if (tflag == 2) {
        mvwaddstr(win, 0, 0, "THE ROBOT HAS FALLEN");
      }
      if (zy == ey) {
        if (zx == ex) {
          j = rand() % (3 + 1 - 0) + 0;
          zx = rand() % (35 + 1 - 0) + 0;
          zy = rand() % (15 + 1 - 0) + 0;
          mvwaddch(win, zy, zx, cig[2]);
          ex = rand() % (35 + 1 - 0) + 0;
          ey = rand() % (15 + 1 - 0) + 0;
          mvwaddch(win, ey, ex, cig[1]);
          bx = rand() % (35 + 1 - 0) + 0;
          by = rand() % (15 + 1 - 0) + 0;
          mvwaddch(win, by, bx, cig[4]);

          if (j == 1) {
            hflag = 1; 
          }
          tflag = 0;
          lflag++;
        }
      }
      if (hflag == 1) {
        mvwaddch(win, 10, 10, 'H');
          if (zx == 10) {
            if (zy == 10) {
              hflag = 0;
              life += 10;
            }
          }
      } 
      if (zx == bx + 1) {
        if (zy == by) {
          if (ch == 'a') { 
            zx++;
            life -= (e = rand() % (3 + 1 - 0) + 0);
            mvwprintw(win, 19, 5, "%d", life);
            if ((u = rand() % (2 + 1 - 0) + 0) == 1) {
              bx = 90;
              by = 90;
              tflag = 2;
            }
          }
        }
      }
      if (zx == bx - 1) {
        if (zy == by) {
          if (ch == 'd') {
            zx--;
            life -= (e = rand() % (3 + 1 - 0) + 0);
            mvwprintw(win, 19, 5, "%d", life);
            if ((u = rand() % (2 + 1 - 0) + 0) == 1) {
              bx = 90;
              by = 90;
              tflag = 2;
            }
          }
        }
      }
      if (zy == by - 1) {
        if (zx == bx) {
          if (ch == 's') {
            zy--;
            life -= (e = rand() % (3 + 1 - 0) + 0);
            mvwprintw(win, 19, 5, "%d", life);
            if ((u = rand() % (2 + 1 - 0) + 0) == 1) {
              by = 90;
              bx = 90;
              tflag = 2;
            }
          }
        }
      }
      if (zy == by + 1) {
        if (zx == bx) {
          if (ch == 'w') {
            zy++;
            life -= (e = rand() % (3 + 1 - 0) + 0);
            mvwprintw(win, 19, 5, "%d", life);
            if ((u = rand() % (2 + 1 - 0) + 0) == 1) {
              by = 90;
              bx = 90;
              tflag = 2;
            }
          }
        }
      }
      if (life < 1) {
        mvwaddstr(win, 10, 5, "YOU HAVE PERISHED.");
        tflag = 0;
      }
      if (ch == 'a' || ch == 's' || ch == 'w' || ch == 'd') {
        if (dx > 2 || dx < -2 || dy > 2 || dy < -2) {
          if ((dx * dx) > (dy * dy)) {
            if (dx > 0) {
              bx += 1;
            }
            if (dx < 0) {
              bx -= 1;
            }
          }
          if ((dx * dx) < (dy * dy)) {
            if (dy > 0) {
              by += 1;
            }
            if(dy < 0) {
              by -= 1;
            }
          }
        }
      }
    }
    while ((ch = wgetch(win)) != 27);


    
    wrefresh(win);
    endwin();
    
    return 0;
}

