import csv
import plotly
from plotly.graph_objs import Scatter, Layout
import plotly.graph_objs as go


def valid_state(state):
    state_names = ["Alaska", "Alabama", "Arkansas", "American Samoa", "Arizona", "California",
                   "Colorado", "Connecticut", "District of Columbia", "Delaware", "Florida", "Georgia", "Guam", "Hawaii", "Iowa",
                   "Idaho", "Illinois", "Indiana", "Kansas", "Kentucky", "Louisiana", "Massachusetts", "Maryland", "Maine", "Michigan", "Minnesota",
                   "Missouri", "Mississippi", "Montana", "North Carolina", "North Dakota", "Nebraska", "New Hampshire", "New Jersey", "New Mexico", "Nevada",
                   "New York", "Ohio", "Oklahoma", "Oregon", "Pennsylvania", "Puerto Rico", "Rhode Island", "South Carolina", "South Dakota", "Tennessee", "Texas",
                   "Utah", "Virginia", "Virgin Islands", "Vermont", "Washington", "Wisconsin", "West Virginia", "Wyoming"]

    for state_name in state_names:
        if state_name == state:
            return True
    return False


f = open("us-states.csv")
reader = csv.DictReader(f)

fp = open("state-populations.csv")
readerpop = csv.DictReader(fp)

population = {}

for row in readerpop:
    state_name = row["State"].strip(".")
    state_pop = row["Population"].replace(",", "")
    population[state_name] = int(state_pop)

while True:
    state1 = input("1st State: ")
    state2 = input("2nd State: ")
    state3 = input("3rd State: ")
    if valid_state(state1) and valid_state(state2) and valid_state(state3):
        break

x1 = []
y1 = []

x2 = []
y2 = []

x3 = []
y3 = []

previous_total1 = 0
previous_total2 = 0
previous_total3 = 0

for row in reader:
    if row["state"] == state1:
        x1.append(row["date"])
        y1.append(((int(row["cases"]) - previous_total1) / population[state1]) * 100000)
        previous_total1 = int(row["cases"])
    elif row["state"] == state2:
        x2.append(row["date"])
        y2.append(((int(row["cases"]) - previous_total2) / population[state2]) * 100000)
        previous_total2 = int(row["cases"])
    elif row["state"] == state3:
        x3.append(row["date"])
        y3.append(((int(row["cases"]) - previous_total3) / population[state3]) * 100000)
        previous_total3 = int(row["cases"])

trace0 = go.Scatter(x=x1, y=y1, name=state1)
trace1 = go.Scatter(x=x2, y=y2, name=state2)
trace2 = go.Scatter(x=x3, y=y3, name=state3)

graph = {
    "data": [trace0, trace1, trace2],
    "layout": Layout(title=(f"{state1}, {state2} and {state3} comparison daily cases per 100,000"))
}

plotly.offline.plot(graph, filename="statecomparison.html")
