function sum(){
    let total = 0;
    return (s = 0, t = 0) => {
        return total += Math.abs(s - t);
    }
}
function findPermutationDifference(s: string, t: string): number {
    const add = sum();
    for(let i = 0; i < s.length; i++){
        add(i, t.indexOf(s[i]));
    }
    return add();
};  
console.log(findPermutationDifference("abc", "bac"))