
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
  string filename("poke_data.txt");
  vector<string> lines;
  string line;

  ifstream input_file(filename);
  if (!input_file.is_open()) {
    cerr << "Could not open the file - '"
      << filename << "'" << endl;
    return EXIT_FAILURE;
  }

  //vector<vector<string>> vec(493,vector<ll>(11,""));

  while (getline(input_file, line)){
    ull len = line.size();
    ull n = 15;
    vector<string> vec(1,"");
    int cnt = 0;
    bool status = 0;
    for(int i = 0; i< len;i++){
      if(status == 0){
        if(line[i] == '<'){
          if(vec[cnt] != ""){
            vec.push_back("");
            cnt++;
          }
          status = 1;
        }else{
          vec[cnt] += line[i];
        }
      }else{
        if(line[i] == '>'){
          status = 0;
        }
      }
    }
    if(vec[10] != ""){
      for(int i = 0; i < 10;i++){
        vec[i] = vec[i+1];
      }
      cnt--;
    }
    vec[10] = "-";

    vector arr = split(vec[9],'/');
    ull len_arr = arr.size();
    for(int i = 0;i < len_arr;i++){
      vec[9+i] = arr[i];
    }
    cout << endl;

    // cout << cnt << endl;
    for(int i = 0; i < 11;i++){
      cout << vec[i] << " ";
    }
    cout << endl;




    lines.push_back(vec[1]);
  }

  for (const auto &i : lines)
    // cout << i << endl;

  input_file.close();
  return EXIT_SUCCESS;
}