
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a=b; return 1; } return 0; }
#define rep(i, n) REP(i, 0, n)
#define rep_rev(i, n) for (int (i) = (int)(n) - 1 ; (i) >= 0 ; --(i))
#define ALL(v) v.begin(), v.end()
#define MSG(a) cout << #a << " " << a << endl;
#define REP(i, x, n) for(int i = x; i < n; i++)
#define all(x) (x).begin(),(x).end()
ll t1,t2,t3;
const ll mod = 1000000007;
const int INF = 1e9;
const ll INFLONG = 1e18;

using std::cout; using std::cerr;
using std::endl; using std::string;
using std::ifstream; using std::vector;

vector<string> split(const string &s, char delim) {
    vector<string> elems;
    stringstream ss(s);
    string item;
    while (getline(ss, item, delim)) {
    if (!item.empty()) {
            elems.push_back(item);
        }
    }
    return elems;
}

int main()
{
  string filename("datasets/input/poke_general.txt");
  vector<string> lines;
  string line;

  ifstream input_file(filename);
  if (!input_file.is_open()) {
    cerr << "Could not open the file - '"
      << filename << "'" << endl;
    return EXIT_FAILURE;
  }

  int MAX = 493;

  vector<vector<string>> vec(MAX,vector<string>(1,""));
  int ind = 0;

  while (getline(input_file, line)){
    if(ind == MAX){
      break;
    }
    ull len = line.size();
    int cnt = 0;
    bool status = 0;
    for(int i = 0; i< len;i++){
      if(status == 0){
        if(line[i] == '<'){
          if(vec[ind][cnt] != ""){
            vec[ind].push_back("");
            cnt++;
          }
          status = 1;
        }else{
          vec[ind][cnt] += line[i];
        }
      }else{
        if(line[i] == '>'){
          status = 0;
        }
      }
    }
    if(vec[ind][10] != ""){
      for(int i = 0; i < 10;i++){
        vec[ind][i] = vec[ind][i+1];
      }
      cnt--;
    }
    vec[ind][10] = "-";

    vector arr = split(vec[ind][9],'/');
    ull len_arr = arr.size();
    for(int i = 0;i < len_arr;i++){
      vec[ind][9+i] = arr[i];
    }
    cout << endl;
    for(int i = 0; i < 11;i++){
      cout << vec[ind][i] << " ";
    }
    cout << endl;
    ind++;
  }

  cout << vec[492][1] << endl;
  sort(all(vec),[](const vector<string>& x, const vector<string>& y) { return stoi(x[0]) < stoi(y[0]);});
  // rep(i,MAX){
  //   rep(j,11){
  //     cout << vec[i][j] << " ";
  //   }
  //   cout << endl;
  // }

  rep(i,MAX){
    rep(j,11){
      cout << vec[i][j] << " ";
    }
    cout << endl;
  }

  input_file.close();




  ofstream outputfile("datasets/generate/poke_general.txt");


  rep(i,MAX) {
    rep(j,11) {
      outputfile << vec[i][j] << " ";
    }
    outputfile<<"\n";
  }
  outputfile.close();

  return EXIT_SUCCESS;
}