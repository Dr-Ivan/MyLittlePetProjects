const inputLine = document.getElementById("inputLine");
const outputLine = document.getElementById("out");

function msg () {
    outputLine.value = inputLine.value;
}

function addToInput(txt){
    inputLine.value += txt;
}

function resetInput(){
    inputLine.value = "";
}

function calculate(){
    try{
        inputLine.value = eval(inputLine.value);
    } catch (error){
        inputLine.value = "ERROR";
    }
}