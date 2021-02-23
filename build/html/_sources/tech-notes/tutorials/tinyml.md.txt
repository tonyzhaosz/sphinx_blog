# Basics of Machine Learning on Embedded Systems

## Fundamentals about machine learning

Traditional algorithm works in a way that given raw data and rules, an algorithm is to produce `deterministic` output(s). AI/ML is a `probabilistic` way of presenting inference. A typical process for AI/ML is as follows:
* Users provide raw data and expected results and leverage AI/ML algorithms to produce certain `rules` or `models`. This is known as training phase.
* Then, the rules/models would be used to produce `probabilistic` predictions given raw data. This is known as inference phase.

The following figure illustrates such phases:

![Two phases in ML](https://gitee.com/tz_se/blog_pics/raw/master/machine_learning/ML_basics_0.PNG)

For instance, during the training phase, ML is trained to detect cat from photos based on a huge database. Then, during inference phase, the model is able detect a cat from a non-precedented photo with 90% accuracy.

## ARM core support for ML

* ARM presents where tinyML could be used for:

    ![Where tinyML could be used](https://gitee.com/tz_se/blog_pics/raw/master/machine_learning/tinyML_applications.PNG)

* The ARM core portfolio for ML support:

    ![ARM core portfolio for ML](https://gitee.com/tz_se/blog_pics/raw/master/machine_learning/arm_core_ml_0.PNG)

    ![Suggested application vs ARM core](https://gitee.com/tz_se/blog_pics/raw/master/machine_learning/arm_core_ml_4.PNG)

    ![More info on Cortex-M55](https://gitee.com/tz_se/blog_pics/raw/master/machine_learning/arm_core_ml_1.PNG)

    ![More info on NPU core](https://gitee.com/tz_se/blog_pics/raw/master/machine_learning/arm_core_ml_2.PNG)

* TensorFlow Lite deployment on ARM Core

    ![ARM core portfolio for ML](https://gitee.com/tz_se/blog_pics/raw/master/machine_learning/arm_core_ml_3.PNG)

## ML software framework based on ARM core

* The usage of CMSIS-NN lib for optimization:

    ![CMSIS-NN for software framework](https://gitee.com/tz_se/blog_pics/raw/master/machine_learning/ml_sw_arm_0.PNG)

* Optimization based on SIMD instructions:

    ![SIMD optimization](https://gitee.com/tz_se/blog_pics/raw/master/machine_learning/ml_sw_arm_1.PNG)


## Datasets and feature extraction

Collecting datasets serves as the elementary step in ML. The dataset should be collect in an imbalanced fashion to prevent naive classifiers (i.e., always predicts the same class regardless of the input). An example of 'bad' datasets is: 99% of field photos and 1% of dog photos would only result in field prediction.


## Neural networks

Very helpful introduction of NN could be found in this link https://victorzhou.com/blog/intro-to-neural-networks/. Also append some pics to improve understanding:

![](https://gitee.com/tz_se/blog_pics/raw/master/neural_networks/NN_1.PNG)

![](https://gitee.com/tz_se/blog_pics/raw/master/neural_networks/NN_2.PNG)

![](https://gitee.com/tz_se/blog_pics/raw/master/neural_networks/NN_3.PNG)

![](https://gitee.com/tz_se/blog_pics/raw/master/neural_networks/NN_4.PNG)

![](https://gitee.com/tz_se/blog_pics/raw/master/neural_networks/NN_5.PNG)

![](https://gitee.com/tz_se/blog_pics/raw/master/neural_networks/NN_6.PNG)

![](https://gitee.com/tz_se/blog_pics/raw/master/neural_networks/NN_7.PNG)


## References

In this article, Signal processing is key to embedded machine learning (https://www.edgeimpulse.com/blog/dsp-key-embedded-ml), there is a paragraph describing the difference between traditional DSP and ML (duplicated below).

> The result of the signal processing is then interpreted through simple rule-based systems. E.g. a message is sent when the total energy in a signal crosses a threshold. While these systems work it's hard to detect complex events, as you'd need to program out every potential state.

> You can train a machine learning model (not even necessarily a neural network) that looks at all the data in your dataset, cluster these based on the output of a signal processing pipeline (using K-means clustering), and then compare new data to the clusters. The model learns all the potential variations in your data and creates thresholds that are much more precise and fine-grained as you could build by hand.

Notice the word `precise` and `fine-grained` in ML.
