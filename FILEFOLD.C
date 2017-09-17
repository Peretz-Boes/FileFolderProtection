#include<stdio.h>
#include<conio.h>
#include<dos.h>
#include<io.h>
void main(){
int i,test;
char ch,FN[20];
char s[]={"#File/Folder Protection Software\n"};
start:
clrscr();
gotoxy(14,5);
textcolor(2);
cprintf("___________________________________");
gotoxy(14,6);
cprintf("___________________________________");
gotoxy(14,10);
cprintf("___________________________________");
gotoxy(18,8);
textcolor(10);
for(i=0;s[i]!='\0';i++){
_setcursortype(1);
cprintf("%c",s[i]);
delay(50);
sound(1500);
nosound();
}
textcolor(2);
gotoxy(22,12);
cprintf("1:Hide a file or folder\n");
gotoxy(22,14);
cprintf("2:Show a file or folder\n");
gotoxy(22,16);
cprintf("3:Help\n");
gotoxy(16,18);
cprintf("Enter your choice\n");
ch=getch();
if(ch==27){
exit(1);
}
switch(ch){
case '1':
clrscr();
gotoxy(15,6);
textcolor(2);
cprintf("___________________");
gotoxy(15,7);
cprintf("___________________");
gotoxy(15,12);
cprintf("__________________");
gotoxy(17,9);
cprintf("Enter file/folder name with the path");
gotoxy(17,11);
cprintf("$:");
fflush(stdin);
gets(FN);
test=_chmod(FN,1,FA_SYSTEM|FA_HIDDEN|FA_RDONLY);
if(test==-1){
clrscr();
gotoxy(19,9);
delay(200);
sound(1000);
nosound();
cprintf("Unable to hide file/folder");
}else{
clrscr();
gotoxy(19,9);
cprintf("Operation executed successfully\n");
}
break;
case '2':
clrscr();
gotoxy(15,6);
textcolor(2);
cprintf("___________________");
gotoxy(15,7);
cprintf("___________________");
gotoxy(15,12);
cprintf("__________________");
gotoxy(17,9);
cprintf("Enter file/folder name with the path");
gotoxy(17,11);
cprintf("$:");
fflush(stdin);
gets(FN);
test=_chmod(FN,1,0);
if(test==-1){
clrscr();
gotoxy(19,9);
delay(200);
sound(1000);
nosound();
cprintf("Unable to show file/folder");
}else{
clrscr();
gotoxy(19,9);
cprintf("Operation executed successfully\n");
}
break;
case '3':
clrscr();
gotoxy(9,6);
textcolor(2);
cprintf("__________");
gotoxy(9,7);
cprintf("__________");
gotoxy(9,16);
cprintf("__________");
gotoxy(14,9);
cprintf("Enter full path of file/folder in the following format\n");
gotoxy(16,11);
cprintf("Example:If your file/folder is present in the E drive\n");
gotoxy(24,13);
cprintf("Them E:\\file name or folder name\n");
gotoxy(12,15);
cprintf("Note:Providing the extension of file is compulsory\n");
break;
default:
clrscr();
sound(1000);
gotoxy(19,9);
cprintf("The selection you have entered is invalid\n");
nosound();
break;
}
delay(2000);
goto start;
}
