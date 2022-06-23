const calculate = (value1:number, value2:number) => {
    if (!Number.isInteger(value1) || !Number.isInteger(value2)) {
        return 0;
    }
    else if (value1 == 0 || value2 == 0) {
        return 0;
    }
    else {
        value1 < 0 ? value1 = -value1 : value1;
        value2 < 0 ? value2 = -value2 : value2;
        let larger = value1 > value2 ? value1 : value2;
        let smaller = value1 < value2 ? value1 : value2;
        let temp = Math.floor(larger % smaller);
        while (temp) {
            larger = smaller;
            smaller = temp;
            temp = larger % smaller;
        }
        ;
        return smaller;
    }
    ;
};
const value1:number = 35;
const value2:number = 25;
console.log(calculate(value1, value2));