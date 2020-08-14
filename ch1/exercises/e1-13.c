/* prints histogram of word lenghts */
int main() {
   int c = 0;
   int lenghts[30];  // array hoding lenghts of words
   int wordLen = 0;  // current word lenght
   int longest = 0;  // longest word lenght
   int maxCnt = 0;   // most frequent word lenght

   // sets word counts to 0
   int i = 0;
   for(i = 0; i < 30; ++i)
      lenghts[i] = 0;

   // counts number of letters in word
   while((c = getchar()) != EOF) {
      if(c == ' ' || c == '\t' || c == '\n') { // checks for end of word
         lenghts[wordLen]++;
         if(lenghts[wordLen] > maxCnt) // checks for most frequent lenght
            maxCnt = lenghts[wordLen];
         wordLen = 0;
      }  else {      // counts length of current word
         wordLen++;
      }
      if(longest < wordLen) // gets maximum word lenght
         longest = wordLen;
   }

   // prints histogram data verticaly row by row
   for(; maxCnt > 0; --maxCnt) { // maxCnt is used as Y axis value in our histogram
      printf("%d", maxCnt); // prints numbers to the right
      for(i = 0; i <= longest; ++i)  // prints dashes or spaces
         if(lenghts[i] >= maxCnt)   // prints - if word lenght is greater or equal to Y axis value
            printf("- ");
         else // prints SPACE if word lenght is smaller than Y accis value
            printf("  ");

      printf("\n");
   }

   // prints letter count on X axis
   printf("  ");
   for(i = 0; i < longest; ++i){
      printf(" %d",i);
   }
   printf("\n");

   return 0;
}
