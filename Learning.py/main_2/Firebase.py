import firebase_admin
from firebase_admin import credentials
from firebase_admin import db

# Fetch the service account key JSON file contents
cred = credentials.Certificate('main_2/first-firebase-1ff0c-firebase-adminsdk-fbsvc-bfbc025aed.json')

# Initialize the app with a service account, granting admin privileges
firebase_admin.initialize_app(cred, {
'databaseURL': 'https://first-firebase-1ff0c-default-rtdb.asia-southeast1.firebasedatabase.app/'
})

# As an admin, the app has access to read and write all data, regradless of Security Rules

ref = db.reference('')
print(ref.get())

ref = db.reference('User')
print(type(ref.get()))

#users_ref = ref.child('User')
#users_ref.set({
    #'alanisawesome': {
        #'date_of_birth': 'June 23, 1912',
        #'full_name': 'Alan Turing'
    #},
    #'gracehop': {
        #'date_of_birth': 'December 9, 1906',
        #'full_name': 'Grace Hopper'
    #}
#})

hopper_ref = ref.child('Moris')
hopper_ref.update({
    'Ages': 32,'Job':'Doctor','Email':'Moris.hehehe@gmail.com','Phone number':'234-726-9998'
})

hopper_ref = ref.child('Moris/Job')
hopper_ref.delete()
