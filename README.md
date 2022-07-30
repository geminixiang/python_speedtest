# It's a test for CPP、Python、Numba in the same function.

## Step1. Build CPP
```bash
g++ -O3 -Wall -shared -std=c++14 -fPIC `python3 -m pybind11 --includes` some.cpp -o gemini`python3-config --extension-suffix` `python3-config --ldflags`
```

## Step2. Run test
```python
python test
```