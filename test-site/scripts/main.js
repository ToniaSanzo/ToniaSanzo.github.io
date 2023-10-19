// Functions -------------------------------------------------------------------
function setUserName() {
    const myName = prompt("Please enter your name.");
    if (!myName) {
        setUserName();
    }
    else {
        localStorage.setItem("name", myName);
        myHeading.textContent = `Welcome to Thingamabob ${myName}!`;
    }
}


// Script Body -----------------------------------------------------------------
const myImages = document.querySelectorAll("img");

for (let imageIndex = 0; imageIndex < myImages.length; ++imageIndex)
{
    var currentImage = myImages.item(imageIndex); 
    currentImage.onclick = () => {
        const mySrc = currentImage.getAttribute("src");
        if (mySrc === "images/cheshire-cat.png") {
            currentImage.setAttribute("src", "images/cheshire-cat2.png");
        }
        else if (mySrc === "images/cheshire-cat2.png") {
            currentImage.setAttribute("src", "images/cheshire-cat.png");
        }
      };
}

let myButton = document.querySelector("button");
let myHeading = document.querySelector("h1");
  

if (!localStorage.getItem("name")) {
    setUserName();
} else {
    const storedName = localStorage.getItem("name");
    myHeading.textContent = `Welcome to Thingamabob ${storedName}!`;
}
  
myButton.onclick = () => {
    setUserName();
};
  
