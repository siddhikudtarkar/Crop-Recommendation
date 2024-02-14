# Crop-Recommendation Final Year Project

Developed a Crop Recommendation System using Machine Learning and IoT

Designed and implemented an IoT sensor network to collect real-time environmental data (soil moisture, temperature, humidity) using ESP8266 NodeMCUs.

Employed Machine Learning techniques to analyze sensor data and generate crop recommendations based on historical yield data and environmental conditions.

Built a user-friendly web interface using Flask to display crop recommendations and relevant information to farmers.

This project aimed to increase crop yields, optimize resource usage, and promote sustainable agricultural practices.


Based on the image you sent, here’s a breakdown of a possible way to set up a crop recommendation system using machine learning (ML) and the Internet of Things (IoT), along with website development:

## Data Collection:

Sensors: Various sensors capture environmental data like soil moisture, temperature, and humidity from the field.
ESP8266 NodeMCU WiFi development boards: These boards collect sensor data and transmit it to the cloud platform.

## Data Storage and Processing:
Firebase: 
This cloud platform stores the sensor data, making it accessible for the ML model.

## Data Training: 
The data collected from the sensors is used to train the ML model.
Python and Pickle: Python is used for data manipulation and analysis, while Pickle helps store the trained ML model for later use.
Analysis and Recommendation:

## Machine Learning Model: 
This trained model analyzes the sensor data to recommend suitable crops for the current conditions.
User Interface:

## Flask: 
This Python framework helps build the web application backend that interacts with the ML model.

Front End: This refers to the website’s user interface where recommendations are displayed.


## Overall Process:

Sensor data is collected and sent to the cloud platform.

The ML model analyzes the data and generates crop recommendations.

The web application displays these recommendations to the user.

## Benefits:

Increased yields: By planting suitable crops based on data-driven insights, farmers can potentially improve yields.

Reduced costs: Optimized resource usage based on recommendations can lead to cost reductions.

Improved sustainability: Precision agriculture practices recommended by the system can promote resource conservation.
