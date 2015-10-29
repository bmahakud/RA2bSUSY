enum binning { kRA2 , k13TeV , kNumBinning };

int classicRA2(double MHT, double HT, int NJets){

  

  return -1 ;

}

int scrabble(double MHT, double HT, double NJets ){

  //cout << "SCRABBLE" << endl;
  

  if( MHT < 200 || HT < 500 || NJets < 4 ) return -1 ;

  int binHTMHT = -1;
  int binNJet = -1;

  if( MHT > 200 && MHT < 300 ){

    

    if( HT > 500 && HT < 800 ){ 
      binHTMHT = 1;
     // cout << "HTMHT1" << endl;
      }else if( HT > 800 && HT < 1200 ){ 
      binHTMHT = 2;
     // cout << "HTMHT2" << endl;
      }else if( HT > 1200 ){ 
      binHTMHT = 3;
     // cout << "HTMHT3" << endl;
      }else{ 
      return -1;
           }



   }else if( MHT > 300 && MHT < 500){

    if( HT > 500 && HT < 800 ){ 
      binHTMHT = 4;
      //cout << "HTMHT4" << endl;
      }else if( HT > 800 && HT < 1200 ){ 
      binHTMHT = 5;
      //cout << "HTMHT5" << endl;
      }else if( HT > 1200 ){ 
      binHTMHT = 6;
     // cout << "HTMHT6" << endl;
      }else{ 
      return -1;
           }




  }else if( MHT > 500 && MHT < 750 ){

    //cout << "med MHT" << endl;
    if( HT > 500 && HT < 800 ){ 
      binHTMHT = 7;
      //cout << "HTMHT7" << endl;
      }else if( HT > 800 && HT < 1200 ){ 
      binHTMHT = 8;
      //cout << "HTMHT8" << endl;
      }else if( HT > 1200 ){ 
      binHTMHT = 9;
      //cout << "HTMHT9" << endl;
      }else{ 
      return -1;
           }


  }else if( MHT > 750 ){

    //cout << "high MHT" << endl;

    if( HT > 800 && HT < 1200 ){
      binHTMHT = 10 ;
     // cout << "HTMHT10" << endl;
      }else if(HT > 1200){
      binHTMHT =11 ;
     // cout << "HTMHT11" << endl;
      }else{
      return -1;
           }



  }else{ 
    return -1;
       }



  if( NJets == 4  ){
      //low NJet
      binNJet = 0 ;
      //cout<<"NJets1"<<endl;
  }else if( NJets ==5){
      //Medium NJet
      binNJet = 1 ;
      //cout<<"NJets2"<<endl;
  }else if(NJets==6){
      binNJet = 2 ;
     // cout<<"NJets3"<<endl;
  }else if(NJets>=7 && NJets <=8){
      binNJet = 3 ;
     // cout<<"NJets4"<<endl;
  }else if( NJets >= 9 ){
      //High NJet
      binNJet = 4;
     // cout<<"NJets5"<<endl;
  }else{
     return -1;
       }

  //cout << "binNJet: " << binNJet << endl;
  //cout << "binHTMHT: " << binHTMHT << endl;

  return binNJet*11+binHTMHT ;



}



int  computeBin(double MHT, double HT, double NJets,binning bins = k13TeV){
  
  //cout << "computeBin" << endl;

  if( bins == kRA2 ) return classicRA2( MHT , HT , NJets ) ;  
  else if( bins == k13TeV ) return scrabble( MHT , HT , NJets ) ;  
  else { 
    cout << "computeBin() No binning found!" << endl;
    return -1; 
  }

}
