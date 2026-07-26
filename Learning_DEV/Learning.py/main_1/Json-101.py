import json

def read_json():
    x='{"name":"liar","age":23,"city":"clover"}'
    y = json.loads(x)
    print(y["city"])

def write_json():
    x={
    "name":"liar",
    "age":23,
    "city":"clover"
    }

    y = json.dumps(x)
    print(y)


read_json()
write_json()