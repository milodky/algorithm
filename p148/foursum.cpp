#include <iostream>
#include <vector>
#include <algorithm> 
#include <unordered_map>
#include <unordered_set>
#include "math.h"


using namespace std;
/*
vector<vector<int> > threeSum(vector<int> &num);
int threeSumClosest2(vector<int> &num, int target);
int threeSumClosest(vector<int> &num, int target);
vector<int> twoSum(vector<int> &numbers, int target); 
*/

vector<vector<int> > fourSum(vector<int> &num, int target);
int main(){
	
	/* 3Sum problem
	int num[] = {-1, 0, 1, 2, -1, -4};
	//int num[] = {-1, 0, 0, 1};
	//int num[] = {-2, 0, 1, 1, 2};
	//int num[] = {-4,-2,1,-5,-4,-4,4,-2,0,4,0,-2,3,1,-5,0};
    std::vector<int> numbers(num, num + sizeof(num)/sizeof(int));
	vector<vector<int> > ans = threeSum(numbers);
	*/
	/* 3Sum Closet
	//int num[] = {-1, 2, 1, -4};
	//int num[] ={0,0,0};
	int num[] = {1,1,-1,-1,3};
	std::vector<int> numbers(num, num + sizeof(num)/sizeof(int));
	int ans = threeSumClosest(numbers,1);
	*/
	int num[] = {1, 0, -1, 0, -2, 2};
    std::vector<int> numbers(num, num + sizeof(num)/sizeof(int));
	vector<vector<int> > ans = fourSum(numbers,0);

}
/*
vector<int> twoSum(vector<int> &numbers, int target) {
        vector<int> ans;
        int size = numbers.size();
        int other;
        std::unordered_map<int,int> mymap;
        
        for(int i = 0; i < size; i++){
            other = target - numbers[i];
			std::unordered_map<int,int>::const_iterator got = mymap.find (other);
            if(got != mymap.end()){
                ans.push_back(mymap.at(other)+1);
				ans.push_back(i+1);
				return ans;
			}
            else{
				std::pair<int,int> in (numbers[i],i);
				mymap.insert(in) ;
			}
        }
    }
	*/
//4Sum

vector<vector<int> > fourSum(vector<int> &num, int target) {
	vector<vector<int>> ret;
    //First store all the 2sum
	unordered_map<int, unordered_set<pair<int,int>>> mymap;
	for(int i = 0; i < num.size() - 1;++i){
		for(int j = i + 1; j < num.size();++j){
			int sum = num[i] + num[j];
			std::unordered_map<int,unordered_set<pair<int,int>>>::iterator got = mymap.find (sum);
			if(got != mymap.end()){
				(got->second).insert(std::make_pair<int&, int&>(num[i], num[j]));
			}
			else{
				//mymap.insert(std::make_pair(sum,std::make_pair<int&, int&>(num[i],num[j])));
			}
		}
	}
	/*
	//Find 2sum again
	unordered_map <int, unordered_set<pair<int&,int&>>> myhash;
	for(unordered_map<int, unordered_set<pair<int&,int&>>>::const_iterator map_iter = mymap.begin(); map_iter != mymap.end(); map_iter++){
		int sum1 = map_iter->first;
		int sum2 = target - sum1;
		if(myhash.count(sum2) == 0){
			myhash.insert(std::make_pair(sum2, map_iter->second));
		}
		else{
			vector<int> sol;
			for(unordered_set<pair<int&,int&>>::const_iterator i = (map_iter->second).begin(); i != (map_iter->second).end();i++){
				sol.push_back(i->first);
				sol.push_back(i->second);
				for(unordered_set<pair<int&,int&>>::const_iterator j = myhash.at(sum2).begin(); j != myhash.at(sum2).end(); j++){
					sol.push_back(j->first);
					sol.push_back(j->second);
					std::sort(sol.begin(),sol.end());
					ret.push_back(sol);
					sol.clear();
				}
			}
		}
	}
	*/
	//Return
	return ret;
}

/*
int threeSumClosest(vector<int> &num, int target){
	std::sort(num.begin(), num.end());  
	int len = num.size();  
	int minV = INT_MAX, record;  
	for(int i =0; i< len-2; i++){        
		int start = i+1, end =len-1;             
		while(start<end){  
          int sum = num[i] + num[start] + num[end];  
		  if(sum == target){   
		     minV = 0;  
             record = sum;  
	         break;  
	      }  
          if(sum < target){  
				if(target-sum < minV){  
					 minV = target-sum;  
					 record = sum;  
				}  
            start++;            
          }  
          else  
          {  
            if(sum-target < minV)  
            {  
              minV = sum - target;  
              record = sum;  
            }  
            end--;  
          }  
        }        
        while(i<len-3 && num[i] == num[i+1]) i++;  
      }  
      return record;  
}
*/
//3Sum closest
/*
int threeSumClosest2(vector<int> &num, int target) {
	int result;
	int ret = numeric_limits<int>::max();
	int diff;
	std::sort(num.begin(),num.end());
    for(int i = 0;i<num.size()-2;i++){
		for(int j = i + 1;j<num.size()-1;j++){
			int ind = j + 1 + (num.size()-1-j)/2;
			if(num[i]+num[j]+num[ind]>target){
				while(num[i]+num[j]+num[ind]>target&&ind>=j+2){
					ind --;
				}
				if(num[i]+num[j]+num[ind]>target){
					diff =  (num[i]+num[j]+num[ind])-target;
					if(ret>diff){
						ret = diff;
						result = (num[i]+num[j]+num[ind]);
					}
				}
				else if(target-(num[i]+num[j]+num[ind])>(num[i]+num[j]+num[ind+1])-target){
					diff = num[i]+num[j]+num[ind+1]-target;
					if(ret>diff){
						ret = diff;
						result = (num[i]+num[j]+num[ind+1]);
					}
				}
				else{
					diff = target-(num[i]+num[j]+num[ind]);
					if(ret>diff){
						ret = diff;
						result = (num[i]+num[j]+num[ind]);
					}
				}

				
			}
			else if(num[i]+num[j]+num[ind]<target){
				while(num[i]+num[j]+num[ind]<target&&ind<num.size()-1){
					ind ++;
				}
				if(num[i]+num[j]+num[ind]<target){
					diff = target-(num[i]+num[j]+num[ind]);
					if(ret>diff){
						ret = diff;
						result = (num[i]+num[j]+num[ind]);
					}
				}
				else if((num[i]+num[j]+num[ind])-target<target - (num[i]+num[j]+num[ind-1])){
					diff = (num[i]+num[j]+num[ind])-target;
					if(ret>diff){
						ret = diff;
						result = (num[i]+num[j]+num[ind]);
					}
				}
				else{
					diff = target - (num[i]+num[j]+num[ind-1]);
					if(ret>diff){
						ret = diff;
						result = (num[i]+num[j]+num[ind-1]);
					}
				}

			}
			else{
				return target;
			}
			
		}
	}
	return result;
}
*/
//Three Sum problem
/*
vector<vector<int> > threeSum(vector<int> &num) {
       
	vector<vector<int>> res;
	vector<int> inRes;
	std::sort (num.begin(), num.end());
	if(num.size()<3)
    	    return  res;
	for(int i=0;i<num.size()-2;i++){
		while(i>0 && num[i] ==num[i-1]){
			i++;
		}
		int j = i+1;
		int k = num.size()-1;
		while(j<k){
			if(num[i]+num[j]+num[k] == 0)
			{
				inRes.push_back(num[i]);
				inRes.push_back(num[j]);
				inRes.push_back(num[k]);
				if(std::find(res.begin(),res.end(),inRes)==res.end()){
					res.push_back(inRes);
					inRes.clear();
				}
				res.push_back(inRes);
				inRes.clear();
				do{
					j++;
					k--;
				}while(num[j]==num[j-1]&&num[k]==num[k+1]);
				
			}
			if(num[i]+num[j]+num[k] > 0){
				k--;
				
			}
			if(num[i]+num[j]+num[k] < 0){
				j++;
			}
		}
	}
	return res;
}
*/
