class TimeLimitedCache {
    constructor() {
        this.cache = new Map();
    }

    set(key, value, duration) {
        const exists = this.cache.has(key) && this.cache.get(key).expires > Date.now();
        
        
        this.cache.set(key, {
            value,
            expires: Date.now() + duration
        });
        
        
        setTimeout(() => {
            if (this.cache.has(key) && this.cache.get(key).expires <= Date.now()) {
                this.cache.delete(key);
            }
        }, duration);
        
        return exists;
    }

    get(key) {
        if (this.cache.has(key) && this.cache.get(key).expires > Date.now()) {
            return this.cache.get(key).value;
        }
        return -1;
    }

    count() {
        let count = 0;
        const now = Date.now();
        
        for (const [key, entry] of this.cache) {
            if (entry.expires > now) {
                count++;
            } else {
                this.cache.delete(key); 
            }
        }
        
        return count;
    }
}
