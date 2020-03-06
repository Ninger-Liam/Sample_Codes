let button = document.getElementById("butt")
let nav = document.querySelector(".navDis")

function appear (){
    document.querySelector("#txt").innerHTML ='<p>On this small block in Greenwich Village, the community that surrounds us has drastically changed compared to what it used to be back when my dad grew up here. It used to be a lot more dangerous, but the community was a lot closer with each other because of it. Now it’s cleaned up its act, and drawn the attention of a lot of NYU students, but hidden beneath this new identity lies aspects of what used to be. Take one stroll down the block and from dawn to dusk one thing is always true: someone is sitting on their stoop.</p>';
    document.getElementById("pg1").style.backgroundImage = "url(stoop.PNG)";

    if (button.style.display == "none") {
        button.style.display = "block"
    } else {
        button.style.display = "none"
    }

    if (nav.style.display == "block") {
        nav.style.display = "none"
    } else {
        nav.style.display = "block"
    }
}