#include
#include
#include
#include

//グローバル変数の宣言
int field[20][20]; //フィールド
int cell[20][20]; //セル。フィールドと重ね合わせて使用。
//プロトタイプ宣言
void create(void); //初めのセルを配置する関数
void draw(void); //セルを描画する関数
void update(void); //セルの生存、誕生、死滅を制御する関数
int getrand(int min,int max); //乱数を生成する関数

int main(){
srand((unsigned int)time(NULL));//乱数の系列を設定
create();
while(1){
system("cls");//画面の初期化
draw();
update();
Sleep(20);
if(kbhit()) break; //何かキーを押したら終了
}
return 0;
}
//0と1でセルを区別する
void create(){
int i,j;
for(i=0;i<20;i++){
for(j=0;j<20;j++){
cell[i][j]=getrand(0,1);
}
}
}
//0と1を四角と入れ替える
void draw(){
int i,j,k,l;
for(i=0;i<20;i++){
for(j=0;j<20;j++){
field[i][j] = cell[i][j];
if(field[i][j]==1){
printf("■");
}else{
printf("□");
}
}
printf("\n");
}
}
//ライフゲームのルール設定
void update(){
int i, j, k, l;
int sum = 0;
int temp[20][20];
for(i = 0; i < 20; i++) {
for(j = 0; j < 20; j++) {
temp[i][j] = cell[i][j];
//端っこのセルを除いての処理をする
if((i != 0)&&(j != 0)&&(i != 19)&&(j != 19)) {
for(k = -1; k < 2; k++) {
for(l = -1; l < 2; l++) {
if((k!=0) || (l!=0)) {
sum += cell[i+k][j+l];
}
}
}
if(cell[i][j]) {
//セルの周りに2つか3つのセルがいたら生存
if((sum != 2) && (sum != 3)) {
temp[i][j] = 0;
}
}
//セルの周りに3つのセルがいたら誕生
else {
if(sum == 3) {
temp[i][j] = 1;
}
}
}
//それ以外は死滅
else {
temp[i][j] = 0;
}
sum = 0;
}
}
//この結果をcellに代入する
for(i = 0;i < 20;i++){
for(j = 0;j < 20;j++){
cell[i][j] = temp[i][j];
}
}
}
//乱数を生成
int getrand(int min,int max){
return min+(int)(rand()*(max-min+1.0)/(1.0+RAND_MAX));
}