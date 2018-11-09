#!/bin/bash
find ./params -name "*.param" | parallel "./build/ss_tp4 {}"