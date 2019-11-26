#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

struct record {
  char word[64 + 1];
  int count;
  struct record *next;
};

struct record *head = NULL;

int read_word_from_file(FILE *fp, char *word)
{
   fscanf(fp, "%[^A-Za-z0-9'-]s", word);
   return fscanf(fp, "%[A-Za-z0-9'-]s", word) != EOF;
}

void add_word_to_list(char *word) {
  struct record *t = malloc(sizeof(struct record));
  strcpy(t->word, word);
  t->count=0; 

  if (head == NULL) {
    head = t;
  }

  // struct record *lq;
  // int v;
  // for (lq = head; lq != NULL; lq = lq->next) {
  //   if (lq->word == word) {
  //   v=1;
  //   lq->count++;
  //   } else v=0;
  // }
  
  // struct record *lp, *p,*q;
  // if(v==1){
  //   for (lp=head; lp!=NULL; lp = lp->next){
  //     if (strcmp(lp->word, word) == 0){
  //       lp->count=lp->count+1;
  //       return;
  //     }
  //   }
  // }

  // if(v==0){
  // q=NULL;
  // for(p=head; p!=NULL;p=p->next){
  //   if (  (strcmp(p->word,word)) >0){
  //     break;
  //   }
  //   q=p;
  // }
  // if (q!=NULL){
  //   q->next=t;
  // } else {
  //   head=t;
  // }
  
  // }
  
  //  cfbfdgfd

  // search, count, add
  struct record *lp, *p,*q;
  for (lp=head; lp!=NULL; lp = lp->next){
    if (strcmp(lp->word, word) == 0){
      lp->count++;
      break;
    }
    //add_list
     else {
      q=NULL;
      // lp->count=1;
      for(p=head; p!=NULL;p=p->next){
        if((strcmp(p->word,word))>0){
          break;
        }
        q=p;
      }
      if (q!=NULL){
        q->next=t;
      } else {
        head=t;
      }
      t->next=p;
    
    }
  }
  
  

//   struct record *lq=NULL;
//  for (lp=head; lp!=NULL; lp = lp->next){
//    if(lp->count==0){
//      if (lq==NULL){
//        head=lp->next;
//      } else {
//        lq->next=lp->next;
//      }
//       free(lp);
//       return;
//    }
//     lq=lp;
//  }
}
  

  //    // search, count, add
  // struct record *lp, *p,*q;
  // for (lp=head; lp!=NULL; lp = lp->next){
  //   if (exitList(word)==0){
  //     q=NULL;
  //     t->count=1;
  //     for(p=head; p!=NULL;p=p->next){
  //       if((strcmp(p->word,word))>0){
  //         break;
  //       }
  //       q=p;
  //     }
  //     if (q!=NULL){
  //       q->next=t;
  //     } else {
  //       head=t;
  //     }
  //     t->next=p;
  //   }
  //   else{
  //    lp->count++;
  //    break;
  //   }
  
  //  struct record *p = head,*q;
  //   while (p) {
  //       if (strcmp(p->word, word) == 0) {
  //           p->count++;
  //           return;
  //       } else  if (strcmp(p->word, word) != 0) {
  //          insert_list(word);
  //       }

  //       else if (p->next == NULL)
  //           break;
  //       p = p->next;
  //   }

  //   p->next = new_word(word);


//insert_list

// void insert_list(char *word) {
//      struct record *t = malloc(sizeof(struct record));
//      strcpy(t->word, word);
//      struct record *lp, *p,*q;
//       q=NULL;
//       // lp->count=1;
//       for(p=head; p!=NULL;p=p->next){
//         if((strcmp(p->word,word))>0){
//           break;
//         }
//         q=p;
//       }
//       if (q!=NULL){
//         q->next=t;
//       } else {
//         head=t;
//       }
//       t->next=p;
// }

// void add_word_to_list(char *word) {
//   struct record *t = malloc(sizeof(struct record));
//   strcpy(t->word, word);
//   t->count=0; 

//   if (head == NULL) {
//     head = t;
//   }
//     struct record *lp, *p,*q;
//     for(p=head; p!=NULL;p=p->next){
//       if((strcmp(p->word,word))==0) {
//         break;
//     }else insert_list(word);
// }
// }


int main(int argc, char *argv[])
{
  FILE *fp;
  char word[64 + 1];
  struct record *p;

  if (argc != 2) {
    fprintf(stderr, "Missing file argument\n");
    return 1;
  }
  
  if ((fp = fopen(argv[1], "r")) == NULL) {
    fprintf(stderr, "Can't open %s\n", argv[1]);
    return 1;
  }

  while (read_word_from_file(fp, word)) {
    add_word_to_list(word);
  }

  fclose(fp);

  for (p = head; p != NULL; p = p->next) {
    printf("%s %d\n", p->word, p->count);
  }

  return 0;
}