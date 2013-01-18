#include<stdio.h>

int input(char, char);
int judge(char);

char line1[18]="| | | |  |7|8|9|\n",
     line2[18]="| | | |  |4|5|6|\n",
     line3[18]="| | | |  |1|2|3|\n",
	 line4[17]=" - - -    - - -\n",
	 line5[17]=" -+-+-    -+-+-\n";


main()
{
    char c,turn='o';
    printf("○×ゲーム\n");
    printf("%s%s%s%s%s%s%s\n",line4,line1,line5,line2,line5,line3,line4);

  while(1){
    while(1){
      if(turn=='o')printf("○先手：数字キーで指定");
      else printf("×後手：数字キーで指定");
      scanf("%c%*[^\n]",&c);getchar();
      if(input(c,turn))printf("もう一度入力してください");
      else break;
    }
    printf("%s%s%s%s%s%s%s\n",line4,line1,line5,line2,line5,line3,line4);
    if(judge(turn))return;
    if(turn=='o')turn='x';
    else turn='o';
  }
}

int input(char c, char piece)
{
  int flg=0;
  switch(c){
    case '1': if(line3[1]==' ')line3[1]=piece ;else flg=1;break;
    case '2': if(line3[3]==' ')line3[3]=piece ;else flg=1;break;
    case '3': if(line3[5]==' ')line3[5]=piece ;else flg=1;break;
    case '4': if(line2[1]==' ')line2[1]=piece ;else flg=1;break;
    case '5': if(line2[3]==' ')line2[3]=piece ;else flg=1;break;
    case '6': if(line2[5]==' ')line2[5]=piece ;else flg=1;break;
    case '7': if(line1[1]==' ')line1[1]=piece ;else flg=1;break;
    case '8': if(line1[3]==' ')line1[3]=piece ;else flg=1;break;
    case '9': if(line1[5]==' ')line1[5]=piece ;else flg=1;break;
    default : flg=1;
  }
  return flg;
}

int judge(char piece)
{
  if(line3[1]==piece &&line3[3]==piece &&line3[5]==piece ||
     line2[1]==piece &&line2[3]==piece &&line2[5]==piece ||
     line1[1]==piece &&line1[3]==piece &&line1[5]==piece ||
     line3[1]==piece &&line2[1]==piece &&line1[1]==piece ){
     if(piece=='o'){printf("○　先手の勝ち\n");return 1;}
     else{printf("○　後手の勝ち\n");return 1;}
  }
  else if(
     line3[3]==piece &&line2[3]==piece &&line1[3]==piece ||
     line3[5]==piece &&line2[5]==piece &&line1[5]==piece ||
     line3[1]==piece &&line2[3]==piece &&line1[5]==piece ||
     line3[5]==piece &&line2[3]==piece &&line1[1]==piece ){
     if(piece=='o'){printf("○　先手の勝ち\n");return 1;}
     else{printf("×　後手の勝ち\n");return 1;}
  }
  else if(line1[1]!=' '&&line1[3]!=' '&&line1[5]!=' '&&
          line2[1]!=' '&&line2[3]!=' '&&line2[5]!=' '&&
          line3[1]!=' '&&line3[3]!=' '&&line3[5]!=' '){
     printf("引き分け\n");return 1;}
  return 0;
}
