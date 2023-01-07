class Solution {
public:
    vector<string> invalidTransactions(vector<string>& transactions) {
        int flag = 0;
        
        vector<string> name;
        vector<int> time;
        vector<int> amount;
        vector<string> city;
        vector<string> result;
        
        //breaking the transactions string into different parts
        for(auto str : transactions){
            stringstream ss(str);
            string st;

            while(getline(ss,st,',')){
                if(flag == 0){
                    name.emplace_back(st);
                    flag = 1;
                }
                else if(flag == 1){
                    time.emplace_back(stoi(st));
                    flag = 2;
                }
                else if(flag == 2){
                    amount.emplace_back(stoi(st));
                    flag = 3;
                }
                else if(flag == 3){
                    city.emplace_back(st);
                    flag = 0;
                }
            }
        }
        
        //checking if amount of transaction is valid
        int j = 0;
        for(auto it : amount){
           if(it > 1000){
               result.emplace_back(transactions[j]);
           }
           j++;
        }

        //checking if the name, city and time of transaction is valid
        for(int i=0;i<transactions.size();i++){
            for(int j=0;j<transactions.size();j++){
                if(name[i] == name[j] && city[i] != city[j]){
                   if(abs(time[i] - time[j]) <= 60){
                      if(amount[i] <= 1000){
                          result.emplace_back(transactions[i]);
                          break;
                      }
                   }
                }
            }
        }

        return result;

    }
};