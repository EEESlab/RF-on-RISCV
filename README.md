

# Optimizing Random Forest Based Inference on RISC-V MCUs at the Extreme Edge

The repository contains the design of three alternative Decision Tree (DT) kernels (DT-Arr, DT-Loop, and DT-Rec) optimized to execute Random Forest (RF) on memory- and compute-constrained RISC-V MCUs.

## Install instructions

Cloning the repository:

```
git clone git@github.com:EEESlab/RF-on-RISCV.git
```

### Getting Started

These instructions were developed using a fresh Ubuntu 16.04 Xenial 64-Bit. We recommend that you set up a Python environment for kernel-codegen using the Conda package management system with a 3.8.5 Python version.
kernel-codegen requires a set of Python packages. You can install them for the local user with:

```
pip install -r requirements.txt
```

To execute the produced RF models on the RISC-V MCU, you need to install and deploy the PULP-SDK (https://github.com/pulp-platform/pulp-sdk).

## kernel-codegen

The directory contains a set of Python scripts necessary to train the model and generate the C code for running on the RISC-V MCU. You can train RF models with train.py and the trained model will be placed under the trained-models directory. Instead the C code is placed in dump-models calling the dump function of the selected DT kernel.

benchmark-0.py generates the C code for a RF model trained on mfeat-factors and vehicle datasets with 16 DTs.

## kernel-on-RISCV-mcu

The directory contains the C code to run RF models on the RISCV MCU for each DT kernel. After producing the C code in kernel-codegen/dump-models, copy such files inside kernel-on-RISCV-mcu and run with:

```
make clean all run
```
