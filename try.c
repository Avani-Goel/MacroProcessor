#include<stdio.h>
#include<conio.h>
#include<string.h>
 
struct mdt
{
    char lab[10];
    char opc[10];
    char oper1[10];
	char oper2[10];
	char oper3[10];
}d[10];
 
void main()
{
    char label[10],opcode[10],operand1[10],operand2[10],operand3[10],newlabel[10],newoperand[10];
    char macroname[10];
    int i,lines,mdtc=1,mntc=1;
    FILE *f1,*f2,*f3,*f4;
    f1 = fopen("MACIN.txt","r");
    f2 = fopen("MACOUT.txt","w");
    f3 = fopen("MDT.txt","w");
    f4 = fopen("MNT.txt","w");
    fscanf(f1,"%s %s %s %s %s",label,opcode,operand1,operand2,operand3);
    printf("1\n");
 
    while(strcmp(opcode,"END")!=0)
    {
        if(strcmp(opcode,"MACRO")==0)
        {
            strcpy(macroname,label);
            printf("%d\t%s\t%s\t%s\t%s\t%d\n",mntc,label,operand1,operand2,operand3,mdtc);
            fprintf(f4,"%d\t%s\t%s\t%s\t%s\t%d\n",mntc,macroname,operand1,operand2,operand3,mdtc);
            mntc++;
            fscanf(f1,"%s%s%s%s%s",label,opcode,operand1,operand2,operand3);
            lines = 0;
            printf("**\n");
            while(strcmp(opcode,"MEND")!=0)
            {
            	printf("%d\t%s\t%s\t%s\t%s\t%s\n",mdtc,label,opcode,operand1,operand2,operand3);
                fprintf(f3,"%d\t%s\t%s\t%s\t%s\t%s\n",mdtc,label,opcode,operand1,operand2,operand3);
                strcpy(d[lines].lab,label);
                strcpy(d[lines].opc,opcode);
                strcpy(d[lines].oper1,operand1);
                strcpy(d[lines].oper2,operand2);
                strcpy(d[lines].oper3,operand3);
                fscanf(f1,"%s %s %s %s %s",label,opcode,operand1,operand2,operand3);
                lines++;
                mdtc++;
            }
            printf("**\n");
        }
        else
        fprintf(f2,"%s\t%s\t%s\t%s\t%s\n",label,opcode,operand1,operand2,operand3);
        fscanf(f1,"%s%s%s%s%s",label,opcode,operand1,operand2,operand3);
        
    }
    fscanf(f1,"%s %s %s %s %s",label,opcode,operand1,operand2,operand3);
    printf("%s\t%s\t%s\t%s\t%s\n",label,opcode,operand1,operand2,operand3);
    fprintf(f2,"%s\t%s\t%s\t%s\t%s\n",label,opcode,operand1,operand2,operand3);
    printf("2\n");
    fclose(f1);
    fclose(f2);
    fclose(f3);
    printf("FINISHED");
    getch();
}