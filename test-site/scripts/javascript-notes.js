const myHeading = document.querySelector("h1");
myHeading.textContent = "Machine Sandbox";


// Variables - containers that store values
let myVariable;
myVariable = "Cat";

let myVariable2 = "Bob";

let myVariable3 = "Tony";
myVariable3 = "Tonia";

// String example
let a = "a";
let b = 'b';

// Number example
let c = 3;

// Boolean example
let d = true;

// Array example
let e = [1, 'Bob', 'Steve', 10];

// Object example
let f = document.querySelector('hi');

/* 
    Comment style 1 
*/

// Comment style 2

// Addition operator
let _1 = 6 + 9;
let _2 = 'good' + ' morning!';

// Subtraction, multiplication, and division operators
let _3 = 9 - 3;
let _4 = 8 * 2;
let _5 = 9 / 3;

// Assignment operator
let _6 = "Working";

// Strict equals
let boolVal = (a === "A"); // returns true/false

// Not and Does-not-equal
boolVal = !boolVal;

let negatedEqualityExample = (b !== 'b');


let iceCream = "chocolate";
if (iceCream === "chocolate") {
    alert("Yay, I love chocolate ice cream!");
} else {
    alert("Awww, but chocolate is my favorite...");
}

// Calls an anonymous function when clicked
document.querySelector("html").addEventListener("click", function () {
    alert("Ouch! Stop poking me!");
});

// Calls an anonymous function when clicked (arrow function alternative)
document.querySelector("html").addEventListener("click", () => {
    alert("Ouch! Stop poking me!");
});
  


