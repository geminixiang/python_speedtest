# It's a speed test for CPP、Python、Numba in the same function.

## Run
### Step1. Check envirement
Python: 3.9

cStandard: c17

cppStandard: c++14

### Step2. Install requirements
```bash
pip install -r requirements.txt
```
### Step3. Build CPP
```bash
g++ -O3 -Wall -shared -std=c++14 -fPIC `python3 -m pybind11 --includes` gemini.cpp -o gemini`python3-config --extension-suffix` `python3-config --ldflags`
```
### Step4. Run test
```python
python test.py
```


## Result
```
cpp using time: 9.5367431640625e-06
by_python using time: 0.007528781890869141
by_numba using time: 3.337860107421875e-06
-----------------------------------------
cpp faster python: 789.45%
cpp faster numba: 0.35%
```