from flask import Flask, request, render_template, flash
import jwt

app = Flask(__name__)

key = "secret"
guest = jwt.encode({"username": "guest"}, key, algorithm="HS256")
admin = jwt.encode({"username": "admin"}, key, algorithm="HS256")

@app.route('/', methods=['GET', 'POST'])
def index():
    if 'Authorization' in request.headers:
        return '{"Error":"This is not where you want to be"}'
    return '{"Error":"Authorization header not found! Login with guest credentials."}'

@app.route('/login', methods=['POST'])
def login():
    if "username" not in request.form or "password" not in request.form:
        return '{"Error":"Missing username or password field."}'
        
    if request.form['username'] == guest and request.form['password'] == guest:
        return f'{"Token":"Bearer {guest}"}'
        
    return 'Login Failed'

@app.route('/flag', methods=['get'])
def flag():
    if 'Authorization' not in request.headers:
        return '{"Error":"Authorization header not found! Login with guest credentials."}'\
    
    if request.header['Authorization'] == f'Bearer {admin}':
        return 'myctf{us3_a_s3cure_k3y_f0r_y0ur_jwt}'


if __name__ == "__main__":
    app.run(host='0.0.0.0', debug=True, port=80)