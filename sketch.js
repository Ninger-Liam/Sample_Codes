let bubbleSize = 20;

let bubble1;

function setup() {
  createCanvas(500,400);
  bubble1 = {
    x: random(0, width),
    y: random(0, height),
    color: {
        r: random(0,255),
        g: random(0,255),
        b: random(0,255)
    }
  };
  bubble2 = {
    x: random(0, width),
    y: random(0, height),
    color: {
        r: random(0,255),
        g: random(0,255),
        b: random(0,255)
    }
  };
  bubble3 = {
    x: random(0, width),
    y: random(0, height),
    color: {
        r: random(0,255),
        g: random(0,255),
        b: random(0,255)
    }
  };
}

function draw() {
  background(0);

  fill(bubble1.color.r, bubble1.color.g, bubble1.color.b);
  circle(bubble1.x, bubble1.y, bubbleSize);
  fill(bubble2.color.r, bubble2.color.g, bubble2.color.b);
  circle(bubble2.x, bubble2.y, bubbleSize);
  fill(bubble3.color.r, bubble3.color.g, bubble3.color.b);
  circle(bubble3.x, bubble3.y, bubbleSize);

  bubble1.x += random(-2, 2);
  bubble1.y += random(-2, 2);
  bubble2.x += random(-2, 2);
  bubble2.y += random(-2, 2);
  bubble3.x += random(-2, 2);
  bubble3.y += random(-2, 2);
}