// client.js
async function fetchData() {
    try {
        const response = await fetch('/api/data');
        const data = await response.json();
        document.getElementById('distance').textContent = `Distance: ${data.distance} cm`;
        document.getElementById('gasValue').textContent = `Gas Level: ${data.gasValue}`;
        if (data.distance < 20) {
            document.getElementById('status').textContent = 'Warning: Trash can 1 is almost full!';
        } else if (data.gasValue > 300) {
            document.getElementById('status').textContent = 'Warning: Gas detected near trash can 1!';
        } else {
            document.getElementById('status').textContent = 'Status: All clear';
        }
    } catch (error) {
        console.error('Error fetching data:', error);
        document.getElementById('distance').textContent = 'Error fetching data';
    }
}

// Fetch data every 4 seconds
setInterval(fetchData, 4000);
