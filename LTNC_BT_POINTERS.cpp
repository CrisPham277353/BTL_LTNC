#include <iostream>
using namespace std;

int myStrlen(char *a);
void reverse(char a[]);
void delete_char(char a[], char c);
void pad_right(char a[], int n);
void pad_left(char a[], int n);
void truncate(char a[], int n);
bool is_palindrome(char a[]);
void trim_left(char a[]);
void trim_right(char a[]);

int main() {
   char a[100] = "memaybeo";
   reverse(a);
   cout << "reverse: " << a << endl;

   char b[100] = "laptrinhnangcao";
   delete_char(b, 'a');
   cout << "delete_char: " << b << endl;

   char c[100] = "haidang";
   pad_right(c, 10);
   cout << "pad_right: " << c << endl;

   char d[100] = "crispham";
   pad_left(d, 10);
   cout << "pad_left: " << d << endl; 

   char e[100] = "skibidi";
   truncate(e, 5);
   cout << "truncate: " << e << endl; 

   char f[100] = "bob";
   if(is_palindrome(f)){
      cout << "is_palindrome: Same" << endl;
   }else{
      cout << "is_palindrome: Not same" << endl;
   }

   char g[100] = "     hi";
   trim_left(g);
   cout << "trim_left: " << g << endl;

   char h[100] = "hi     ";
   trim_right(h);
   cout << "trim_right: " << h << endl;
}

int myStrlen(char *a){
   int length = 0;
   while(a[length] != '\0'){
      ++length;
   }
   return length;
}

void reverse(char a[]){
   char temp;
   int len = myStrlen(a);
   char *start = a;
   char *end = a + len - 1;
   while(start < end){
      temp = *start;
      *start = *end;
      *end = temp;
      start++;
      end--;
   }
}

void delete_char(char a[], char c){
   char *xau = a, *tuhople = a;
   while(*xau != '\0'){
      if(*xau != c){
         *tuhople = *xau;
         tuhople++;
      }
      xau++;
   }
   *tuhople = '\0';
}

void pad_right(char a[], int n){
   int len = myStrlen(a);
   if(len < n){
      for(int i = len; i < n; i++){
         *(a + i) = ' ';
      }
   }
   *(a + n) = '\0';
}

void pad_left(char a[], int n){
   int len = myStrlen(a);
   int addspace = n - len;
   if(len < n){
      for(int i = len; i >= 0; i--){
         *(a + i + addspace) = *(a + i);
      }
      for(int i = 0; i < addspace; i++){
         *(a + i) = ' ';
      }
   }
}

void truncate(char a[], int n){
   if(myStrlen(a) > n){
      *(a + n) = '\0';
   }
}

bool is_palindrome(char a[]){
   int len = myStrlen(a);
   char b[100];
   for(int i = 0; i <= len; i++){
      *(b + i) = *(a + i);
   }
   reverse(b);
   for(int i = 0; i < len; i++){
      if(*(a + i) != *(b + i)){
         return false;
         break;
      }
   }
   return true;
}

void trim_left(char a[]){
   char *start = a;
   while (*start == ' '){
      start++;
   }
   char *dst = a;
   while(*start != '\0'){
      *dst = *start;
      dst++;
      start++;
   }
   *dst = '\0';
}

void trim_right(char a[]){
   int len = myStrlen(a);
   char *end = a + len - 1;
   while(end >= a && *end == ' '){
      end--;
   }
   *(end + 1) = '\0';
}