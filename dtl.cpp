#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <vector>
#include <math.h>
#include <queue>
#include <algorithm>

using namespace std;

double LOG_2 = log10(2);

//Calculate entropy for any pos and neg becasreful about log 0 will cause nan
double calc_entropy(double pos,double neg){
   double p = (double)pos/(double)(pos+neg);
   double n = (double)neg/(double)(pos+neg);
   if (p == 0) {
       p = 1;
   }
   if (n == 0) {
       n = 1;
   }
   
   return -(p*log10(p)/LOG_2+n*log10(n)/LOG_2);
}

//divide the age by agelevel of 10  //ie. 0-10, 10-20 and etc
class NoHeart{
	private:
		int m_ageLevel;
		int m_prior;
		int m_dead;

	public:
		NoHeart( int ageLevel = 1, int prior = 0, int dead = 0 ){
			m_ageLevel = ageLevel;
			m_prior = prior;
			m_dead = dead;
		}

		NoHeart(const NoHeart &p ){
			m_ageLevel = p.getAgeLevel();
			m_prior = p.getPrior();
			m_live = p.getLive();
		}	
		
		int getAgeLevel() const{
		   return m_ageLevel;
	   	}
		
		int getDead() const{
		   return m_dead;
	   	}
		
		int getPrior() const{
		   return m_prior;
	   	}
}



class NHTree{
	private:
		int m_dead, m_pos, m_neg;
		vector<NHTree> m_list;
		vector<NHTree*> m_leaf;
		type = root??

	public:
		NHTree(){
			m_dead = 0;
		}
		
		double get_max_ig(){ //based on ageLevel or prior
			//first get all the age
			vector<int> tested;
			vector<NoHeart> :: iterator it ;
			int age;
			double age_ig = 1.0;
			for (it = m_list.begin();it!= m_list.end() ; it++) {
				int age = (*it).getAgeLevel();
				if (find(tested.begin(), tested.end(), age)==tested.end()) {
				   	tested.push_back(age);
					age_ig -= get_age_ig(age);
				}
       		}
			//now compute prior, if there is any
			double p_ig = 1.0;
			for(int p = 0;p<=1;p+=1){
				p_ig -= get_prior_ig(p);
			}

			if(m_pos > m_neg){
				m_dead = 1;
			}else{
				m_dead = 0;
			}			

			if(p_ig > age_ig){
				tyep = prior
			}else{
				type = age;
			}			
		}

		double get_age_ig(int age){
			vector<NoHeart> :: iterator it;
			int pos = 0;
			int neg = 0;
			for (it = m_list.begin();it!= m_list.end() ; it++){
				if(age = (*it).getAgeLevel()){
					if((*it).getDead() == 1){
						pos += 1;
					}else{
						neg += 1;
					}
				}
			}
			return calc_entropy((double)pos,(double)neg);
		}

		double get_prior_ig(int p){
			vector<NoHeart> :: iterator it;
			int pos = 0;
			int neg = 0;
			for (it = m_list.begin();it!= m_list.end() ; it++){
				if(p = (*it).getPrior()){
					if((*it).getDead() == 1){
						pos += 1;
					}else{
						neg += 1;
					}
				}
			}
			return calc_entropy((double)pos,(double)neg);
		}

		void add_nh(NoHeart &p){
			m_list.push_back(p);
			if(p.getDead()== 1){
				m_pos += 1;
			}else{
				m_neg += 1;
			}
		}

		double train_accuracy(){
			vector<NoHeart> :: iterator it ;
			int correct = 0;
			for (it = m_list.begin();it!= m_list.end() ; it++) {
				if(nh_dtl.test(*it)){
					correct += 1;
				}
       		}
			return (double)correct/(double)(m_pos+m_neg);
		}

//TODO: test
		bool test(NoHeart &p){
			while( root != null){
				//check type
				if(has children){
					root.get_type() == ???
					for(){
						if(children type matches)
							//then check
							root = child
					}
				}
			}
			return (root.dead() == p.getDead());
		}
};




int main(){

	ifstream trainNH("???.txt");
	ifstream testNH("???.txt");
	NHTree nh_dtl = new NHTree();
	if (trainNH.is_open()) {
		int age, prior, dead;
		while (trainLabel.good()) {
		   	trainLabel >> age >> prior >> dead;
			NoHeart p(age,prior,dead);
			nh_dtl.add_nh(p);
		}
	   	trainNH.close();
	}
	cout<<"Accuracy for training data"<<  <<endl;   
	
	//calculate based on entropy
	int nh_count = 0;
	int nh_correct = 0;
	if(testNH.is_good()){
		int age, prior, dead;
		while (trainLabel.good()) {
		   	trainLabel >> age >> prior >> dead;
			NoHeart p(age,prior,dead);
			if(nh_dtl.test(p)){
				nh_correct += 1;
			}
			nh_count += 1;
		}
	   	trainNH.close();
	}
	cout<<"Accuracy for testing data"<<(double)nh_correct/(double)nh_count <<endl;
  	
	
   
    return 0;        
}


