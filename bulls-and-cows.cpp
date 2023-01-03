class Solution {
public:
    string getHint(string secret, string guess) {

        //BULLS HAVE THE CORRECT VALUE AND CORRECT POSITION

        //COWS HAVE THE CORRECT VALUE BUT WRONG POSITION
        
        //creating arrays to store the frequency of each digit in secret & guess
        int secretFreq[10] = {0};
        int guessFreq[10] = {0};
        
        //counting the BULLS
        int bull = 0;
        for(int i=0;i<secret.size();i++){
            if(secret[i] == guess[i]){
                bull++;
            }else{
                secretFreq[secret[i]-'0']++;
                guessFreq[guess[i]-'0']++;
            }
        }
        
        //counting the COWS
        int cow = 0;
        for(int i=0;i<10;i++){
           cow = cow + min(secretFreq[i] , guessFreq[i]);       //finding min between both arrays
        }

        return to_string(bull) + "A" + to_string(cow) + "B";
    }
};