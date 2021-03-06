#include <cstdlib>
#include <iostream>
#include <math.h>

using namespace std;

int main (int argc, char *argv[])
{
    cout << "---------------------------------------" << endl;
    cout << "Cytus TP計算機 [Beta7]" << endl;
    cout << "程式設計 : BrunoLiu" << endl;
    cout << "黑P公式提供 : DarthSagit" << endl;
    cout << "---------------------------------------" << endl;
    
    while (1)
    {
        int Menu = 0;
        printf("<選單>\n");
        printf("輸入1 - 黑P計算 ; 輸入2 - TP計算 ; 輸入3 - 分數計算（未開放） ; 輸入0 - 離開程式\n>>> ");
        scanf("%d", &Menu);
        
        if(Menu==1)
        {
            printf("TP若輸入0將回到選單\n");
            while (1)
            {
                float TP, Gr;
                int AllNotes, Perfect, Good, Bad, Miss, BlackP;
                printf("請輸入TP : ");
                scanf("%f", &TP);
            
                if(TP > 100.00 || TP < 0.0)
                {
                    cout << endl;
                    printf("你的TP打錯囉...\n");
                    printf("TP應介於0~100\n\n");
                }
                else if(TP==0)
                {
                    printf("回到選單...\n");
                    break;
                }
                else
                {
                    printf("請輸入Perfect數 : ");
                    scanf("%d", &Perfect);
                    printf("請輸入Good數 : ");
                    scanf("%d", &Good);
                    printf("請輸入Bad總數 : ");
                    scanf("%d", &Bad);
                    printf("請輸入Miss總數 : ");
                    scanf("%d", &Miss);
                
                    AllNotes = Perfect + Good + Bad + Miss;
                    Gr = ((100.00-TP)/(100.00/AllNotes)-(Miss+Bad)-(0.7*Good))/0.3;
                    BlackP = Gr + 0.5;
                
                    printf("---------------------------------------\n");
                    printf("你的黑P數 : %d\n", BlackP);
                    cout << "你的彩P數 : " << AllNotes-Miss-Bad-Good-BlackP << endl;
                    cout << endl;
                }
            }
        }
        else if(Menu==2)
        {
            float TP = 0;
            int AllNotes, Perfect, Good, Bad, Miss, BlackP, ColorP;
            
            printf("請輸入Perfect數：");
            scanf("%d", &Perfect);
            printf("請輸入黑P數：");
            scanf("%d", &BlackP);
            printf("請輸入Good數：");
            scanf("%d", &Good);
            printf("請輸入Bad數：");
            scanf("%d", &Bad);
            printf("請輸入Miss數：");
            scanf("%d", &Miss);
            
            AllNotes = Perfect+Good+Bad+Miss;
            ColorP = Perfect-BlackP;
            TP = ((100.0*ColorP)/AllNotes)+((70.0*BlackP)/AllNotes)+((30.0*Good)/AllNotes);
            
            printf("你的TP：%.2f\n", TP);
        }
        else if(Menu==3)
        {
            int NoteNum, i, j, AllNotes, Combo = 0;
            float Result = 0.0, Judge = 0;
            int Note[2000];
            
            for (j=0; j<=2000; j++)
            {
                Note[j] = 0;
            }
            
            printf("請輸入總Note數：\n");
            scanf("%d", &AllNotes);
            printf("請輸入第X個Note為何種判定\n");
            while(1)
            {
                printf("輸入第X個Note：(完成請輸入0）\n");
                scanf("%d", &NoteNum);
                if(NoteNum==0) break;
                printf("請輸入判定，Good = 1、Bad = 2、Miss = 3\n");
                scanf("%d", &Note[NoteNum]);
            }
            for (i=1; i<=AllNotes; i++)
            {
                if(Note[i]==1) Judge = 0.7;
                else if(Note[i]==2) Judge = 0.3;
                else if(Note[i]==3) Judge = 0.0;
                else Judge = 1.0;
                
                if(Note[i]==2 || Note[i]==3)
                {
                    Combo = 0;
                }
                Combo++;
                
                Result = Result + (((900000.0/AllNotes)*Judge)+(200000.0/((AllNotes-1.0)*AllNotes))*Combo);
                printf("%f\n\n", Result);
            }
        }
        else if(Menu==0)
        {
            return 0;
        }
        
    }
    system("PAUSE");
    return 0;
}
