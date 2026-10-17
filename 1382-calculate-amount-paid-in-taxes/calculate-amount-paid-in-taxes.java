class Solution {
    public double calculateTax(int[][] brackets, int income) {
      double tax=0.0;
      int prev=0;// to store the prev upper 
      for(int i=0;i<brackets.length;i++){
        int upper=brackets[i][0];
        int percent=brackets[i][1];
        int taxable=Math.min(upper,income)-prev; // amount which is taxable
        if(taxable>0){
            tax+=taxable*percent/100.0; // calculate and update tax..
        }
        prev=upper; // store currrent upper in prev
        if(income<=upper)break;
      }
      return tax;
        
    }
}