let beds = 50
let bedLine = []
for (let i = 0; i < 60; i++) {
  bedLine.push(beds)
}

var ctx = document.getElementById('myChart');
var myChart = new Chart(ctx, {
    type: 'line',
    data: {
        labels: [0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30,
                  31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59],
        datasets: [{
            label: 'Number Sick',
            data: [],
            backgroundColor: [
                'rgba(255, 0, 0, 0.2)'
            ],
            borderColor: [
                'rgba(255, 0, 0, 1)'
            ],
            borderWidth: 1,
            pointRadius: 0,
        },
        {
          label: 'Number of Hospital Beds',
          data: bedLine,
          backgroundColor: [
              'rgba(0, 0, 255, 0.1)'
          ],
          borderColor: [
              'rgba(0, 0, 255, 1)'
          ],
          borderWidth: 1,
          pointRadius: 0,
        },
        {
          label: 'Number of Deaths',
          data: [],
          backgroundColor: [
              'rgba(255, 0.1)'
          ],
          borderColor: [
              'rgba(255, 1)'
          ],
          borderWidth: 1,
          pointRadius: 0,
        },
        {
          label: 'Number Recovered',
          data: [],
          backgroundColor: [
              'rgba(0, 255, 0, 0.1)'
          ],
          borderColor: [
              'rgba(0, 255, 0, 1)'
          ],
          borderWidth: 1,
          pointRadius: 0,
        }
      ]
    },
    options: {
        scales: {
          xAxes: [{
					       display: false,
				         }],
          yAxes: [{
                ticks: {
                    beginAtZero: true,
                    max: number
                }
            }]
        }
    }
});

setInterval(function() {
  myChart.data.datasets[0].data.push(numberSick)
  myChart.data.datasets[2].data.push(numberDead)
  myChart.data.datasets[3].data.push(numberRecovered)
  myChart.update()
}, 600)

function changeBeds() {
  if (document.querySelector("#bedCount").value == ''){
    beds = 50
  } else {
    beds = parseInt(document.querySelector("#bedCount").value)
  }
  myChart.data.datasets[1].data = []
  for (let i = 0; i < 60; i++) {
    myChart.data.datasets[1].data.push(beds)
  }
  myChart.update()
}
