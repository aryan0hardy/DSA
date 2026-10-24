class Solution {
private int convert(String s){
    int[]days={31,28,31,30,31,30,31,31,30,31,30,31};
    int month=Integer.parseInt(s.substring(0,2));
    int date=Integer.parseInt(s.substring(3,5));
    int total=date;
    for(int i=0;i<month-1;i++){
        total+=days[i];
    }
    return total;

}

   public int countDaysTogether(String arriveAlice, String leaveAlice, String arriveBob, String leaveBob) {
        int a1 = convert(arriveAlice);
        int a2 = convert(leaveAlice);
        int b1 = convert(arriveBob);
        int b2 = convert(leaveBob);
        int start = Math.max(a1, b1);
        int end = Math.min(a2, b2);
        if (start > end)
            return 0;
        return end - start + 1;
    }
};