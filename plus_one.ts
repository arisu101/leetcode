function plusOne(digits: number[]): number[] {
  let num = "";
  for (const element of digits) {
    num += element;
  }
  let value = BigInt(num);
  // let value = Number(num);
  value++;
  num = value.toString();

  let array = num.split("").map(Number);
  return array;
}
console.log(plusOne([6, 1, 4, 5, 3, 9, 0, 1, 9, 5, 1, 8, 6, 7, 0, 5, 5, 4, 3]));
