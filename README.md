## PWr_in_Space_ASC

Solution for the theoretical and software task from the second stage of recruitment for the ACS department of the PWr in Space project. It contains a PID controller simulation aimed at stabilizing a rocket in a vertical position.

## Setup (Ubuntu)

Clone the repository:

```bash
git clone https://github.com/spac3tr1p/PWr_in_Space_ASC
cd PWr_in_Space_ASC
```

Create environment and install dependencies:

```bash
python3 -m venv .venv
source .venv/bin/activate
pip install pandas matplotlib
```

## Run

Compile program (requires gcc)

```bash
gcc main.c pid.c -o program.exe
./program.exe
```

File `data.csv` should be created.

```bash
python chart.py
```

Modifying `Kp`, `Ki`, `Kd` in **pid.c** will change the output and the chart itself.

```c
// pid.c
#define Kp 64.0f
#define Ki 5.0f
#define Kd 10.0f
```


