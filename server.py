import pickle 
import numpy as np
from flask import Flask, request, render_template,jsonify 
import firebase_admin
from firebase_admin import credentials
from firebase_admin import db


model = pickle.load(open('RandomForest.pkl','rb'))
app = Flask(__name__,template_folder="templates")


@app.route('/')
def home():
    return render_template('Home.html') 

@app.route('/populate',methods=['POST','GET'])
def populate():
    try:
        if not firebase_admin._apps:
            cred = credentials.Certificate(r'C:\Users\Siddhi\Downloads\Final-Year-Project-master (4)\Final-Year-Project-masterML/db-8211.json')  
            default_app = firebase_admin.initialize_app(cred, {
            'databaseURL': "https://crop-recommendation-syst-ae1ec-default-rtdb.firebaseio.com"})

        ref = db.reference('/TEMPERATURE')
        temp = ref.get()
        ref = db.reference('/HUMIDITY')
        hum = ref.get()
        ref = db.reference('/PH')
        ph = ref.get()
        ref = db.reference('/MOISTURE')
        moist = ref.get() 

        results = {'temperature' : temp, 'humidity' : hum, 'ph' : ph, 'moisture' : moist}
        return jsonify(results)
    except:
            return 'Error'

@app.route('/classify',methods=['POST','GET'])
def classify_type():
    try:
        temp = request.form.get('temperature') 
        hum = request.form.get('humidity') 
        ph = request.form.get('ph') 
        moist = request.form.get('moisture')
        data = np.array([[temp, hum, ph, moist]])
        print(data) 
        crop = model.predict(data)
        cropResult = crop[0]
        print(cropResult)
        print(crop) 
        results = {'crop': cropResult}
        print(results)
        return jsonify(results)
    except:
            return 'Error'

if(__name__=='__main__'):
    app.run(debug=True)        