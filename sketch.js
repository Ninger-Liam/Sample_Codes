const HEALTHY = 0;
const SICK = 1;
const RECOVERED = 2;
const DEAD = 3;

let numberHealth, numberSick, numberRecovered, numberDead;
let people = [];
let number = 100;
let size = 10;
let r0 = 5.7;
let percentOut = 100;
let mortalityRate = 0;

function windowResized(){
    let canvasWidth = document.querySelector("#canvas").clientWidth;
    let canvasHeight = canvasWidth * 0.635;
    resizeCanvas(canvasWidth, canvasHeight);
}

function setup(){
    let canvasWidth = document.querySelector("#canvas").clientWidth;
    let canvasHeight = canvasWidth * 0.635;
    let cnv = createCanvas(canvasWidth, canvasHeight);
    cnv.parent("canvas");

    for (let i = 0; i < number; i++) {
        people[i] = {
            x: random(width),
            y: random(height),
            dx:(percentOut/100) * number > i ? random(1,3) * 2 - 3 : 0,
            dy:(percentOut/100) * number > i ? random(1,3) * 2 - 3 : 0,
            health: HEALTHY,
            infectious: floor(r0) + (random(1) < r0 - floor(r0) ? 1 : 0),
            recoveryTime: 0
        };
    }
    people[0].health = SICK;
    people[0].infectious = max(r0, people[0].infectious);

    numberHealth = number - 1;
    numberSick = 1;
    numberRecovered = 0;
    numberDead = 0;
}

function draw(){
    background(0);
    fill(255);
    text("Healthy: " + numberHealth + " Sick: " + numberSick + " Recovered: " + numberRecovered + " Dead: " + numberDead, 20, 20);

    if (keyIsPressed) {
        if (keyCode == 13) {
            restart();
        }
    }
    for (let i = 0; i < people.length; i++) {
        fill(getColor(people[i]));
        circle(people[i].x,people[i].y, size);

        people[i].x += people[i].dx;
        people[i].y += people[i].dy;

        if (people[i].x > width || people[i].x < 0){
            people[i].dx = -people[i].dx;
        }

        if (people[i].y > height || people[i].y < 0){
            people[i].dy = -people[i].dy;
        }

        if (people[i].health == SICK){
            if (people[i].recoveryTime == 400) {
                let ran = random(0, 100);
                if (ran < mortalityRate) {
                    people[i].health = DEAD;
                    numberSick--;
                    numberDead++;
                    people[i].dx = 0;
                    people[i].dy = 0
                }
            }
            if (people[i].recoveryTime > 600){
                people[i].health = RECOVERED;
                numberRecovered++;
                numberSick--;
            } else {
                people[i].recoveryTime++
            }
        }

        for (let j = 0; j < people.length; j++) {
            if (i != j && socialize(people[i], people[j])
            && people[i].infectious > 0 && people[i].health == SICK && people[j].health == HEALTHY){
                people[j].health = SICK;
                people[i].infectious--;
                numberSick++;
                numberHealth--;
            }

        }
    }
}

function getColor(person){
    if (person.health == HEALTHY) {
        return "blue";
    } else if (person.health == SICK) {
        return "red";
    } else if (person.health == DEAD) {
        return "grey"
    } else {
        return "pink";
    }
}

function socialize(personA, personB) {
    if (dist(personA.x, personA.y, personB.x, personB.y) <= size){
        return true;
    } else {
        return false;
    }
}